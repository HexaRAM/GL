#include "automate.h"
#include <iostream>
#include "../symbole/declaration/num.h"
#include "../symbole/declaration/identificateur.h"
#include <boost/regex.hpp>
#include "../etat/etat0.h"
#include <deque>
using namespace std;

 //     _              _                                 _          
 //    / \     _   _  | |_    ___    _ __ ___     __ _  | |_    ___ 
 //   / _ \   | | | | | __|  / _ \  | '_ ` _ \   / _` | | __|  / _ \
 //  / ___ \  | |_| | | |_  | (_) | | | | | | | | (_| | | |_  |  __/
 // /_/   \_\  \__,_|  \__|  \___/  |_| |_| |_|  \__,_|  \__|  \___|

Automate::Automate()
{
    // init
    this->affichage = false;
    this->analyse = false;
    this->optimisation = false;
    this->execution = false;

    this->code = "";
    this->buffer = "";
    this->lexer = Lexer();

    this->current_state = new Etat0("0");
    this->current_symbole = NULL;

    this->syntaxeChecked = false;
    this->programme = NULL;
}

Automate::Automate(bool affichage, bool analyse, bool optimisation, bool execution, string code)
{
    this->affichage = affichage;
    this->analyse = analyse;
    this->optimisation = optimisation;
    this->execution = execution;

    this->code = code;
    this->buffer = code;
    this->lexer = Lexer();

    this->current_state = new Etat0("0");
    this->current_symbole = NULL;

    this->syntaxeChecked = false;
    this->programme = NULL;
}

Automate::~Automate()
{
    // si les piles symboles ou states ne sont pas vides
    // les vider à coup de delete pour ne pas causer de memory leaks

    /*for (auto *it : states) // contient current_state
    {
        delete it;
    }

    delete current_symbole;

    for (auto *it : symboles)
    {
        delete it;
    }*/
}

/**
 * Public methods
 */
bool Automate::addVariable(const string& name)
{
    if (this->idents.find(name) != this->idents.end())
    {
        // var already exists
        cout << "# L'identificateur `" << name << "` a déjà été utilisé par une autre variable/constante." << endl;
        return false;
    }
    else
    {
        // var doesn't exist
        this->variables[name] = {0, false};
        this->idents.insert(name);
        return true;
    }
}

bool Automate::addConstante(const string& name, int value)
{
    if (this->idents.find(name) != this->idents.end())
    {
        // const already exists
        cout << "# L'identificateur `" << name << "` (" << value << ") a déjà été utilisé par une autre variable/constante." << endl;
        return false;
    }

    // const doesn't exist
    this->constantes[name] = {value};
    this->idents.insert(name);
    return true;
}

bool Automate::instanciateVariable(const string& name, int value)
{

    if (this->idents.find(name) == this->idents.end())
    {
        // idents `name` doesn't exist
        cout << "# La variable " << name << " n'existe pas. Veuillez la créer avant de vouloir lui affecter une valeur." << endl;
        return false;
    }

    map_var::iterator it = variables.find(name);

    if (it == variables.end())
    {
        // var doesn't exist
        cout << "# La variable " << name << " n'existe pas. Veuillez la créer avant de vouloir lui affecter une valeur." << endl;
        return false;
    }

    // var exist
    it->second.instanciated = true;
    it->second.value = value;
    return true;
}

void Automate::displayMemory()
{
    cout << "# Constantes :" << endl;
    for (auto const& it : this->constantes)
    {
        cout << "\tconst " << it.first << " = " << it.second.value << ";" << endl;
    }
    cout << endl << "# Variables : "<< endl;
    for (auto const &it : this->variables)
    {

        cout << "\tvar " << it.first << "; (";
        if (it.second.instanciated)
        {
            cout << "valeur : " << it.second.value;
        }
        else
        {
            cout << "non instanciée";
        }
        cout << ")" << endl;
    }
}

void Automate::execute(OPTIONS option)
{

    // analyse syntaxique
    executeSyntaxicalAnalyse();

    switch (option)
    {
        case ALL:
            executeAll();
        break;

        case CHECKED:
            if (this->optimisation)
            {
                // optimisation
                // modifier directement les instructions
                executeOptimisation();
            }

            if (this->analyse)
            {
                // analyse statique
                executeAnalyse();
            }

            if (this->affichage)
            {
                // affiche le programme (optimisé si -o)
                executeAffichage();
            }

            if (this->execution)
            {
                // execute le programme
                executeExecution();
            }
        break;

        case AFFICHAGE:
            executeAffichage();
        break;

        case ANALYSE:
            executeAnalyse();
        break;

        case OPTIMISATION:
            executeOptimisation();
        break;

        case EXECUTION:
            executeExecution();
        break;

        default:
            cout << "# Error : option inconnue demandée." << endl;
        break;
    }
}

void Automate::displayState()
{
    #ifdef DEBUG
        cout << "\tPile symbole (taille=" << symboles.size() << ") : ";
        cout.flush();
        for (auto const& it : this->symboles)
        {
            cout << *it << " ";
        }

        cout << endl;
        cout << "\tPile state (taille=" << states.size() << ") : ";
        for (auto const& it : this->states)
        {
            cout << *it << " ";
        }
        cout << endl;
        cout << "\tEtat courant avant transition : " << *current_state << endl;
        cout << "\tSymbole sous la tête de lecture : " << *current_symbole << endl;
        cout << "-------------------------------------------------" << endl;

    #endif
}


// manage deque
void Automate::updateState(Etat* e)
{
    states.push_front(e);
    this->current_state = e;
}

void Automate::popSymbole()
{
    symboles.pop_front();
}
void Automate::popAndDeleteSymbole()
{
    Symbole* s = symboles.front();
    this->popSymbole();
    delete s;
}

void Automate::popState()
{
    states.pop_front();
}
void Automate::popAndDeleteState()
{
    Etat* e = states.front();
    this->popState();
    delete e;
}

void Automate::decalage(Symbole* s, Etat* e)
{
    //cout << "\t-> Décalage " << *e << endl;
    symboles.push_front(s);
    this->updateState(e);
    current_symbole = getNext();

    //this->displayState();

    this->current_state->transition(*this, current_symbole);
}

/**
 * réduction avec dépilement manuel pour gérer les cas où on conserve un élément de la pile (le delete créé un segfault [normal])
 */
void Automate::reduction(Symbole* newSymbole)
{
    symboles.push_front(newSymbole); // on pousse le nouveau symbole sur la pile

    Etat* new_state = states.front()->next(newSymbole); // on récupère le nouvel état à partir du haut de la pile

    this->updateState(new_state); // mise à jour de l'état courant

    //this->displayState();

    current_state->transition(*this, current_symbole);
}


/**
 * réduction avec dépilement automatique
 */
void Automate::reduction(int nbSymboles, Symbole* newSymbole)
{
    //cout << "\t-> Réduction : création de " << *newSymbole << " (nbSymboles=" << nbSymboles << ")" << endl;

    // on dépile
    for(int i = 0; i< nbSymboles; ++i)
    {
        Etat* e = states.front();
        states.pop_front();
        delete e;

        Symbole* s = symboles.front();
        symboles.pop_front();
        delete s; 
    }

    this->reduction(newSymbole);
}

Symbole* Automate::getNthSymbole(int n)
{
	return symboles[n];
}

void Automate::validateSyntaxe()
{
    syntaxeChecked = true;
}

void Automate::executeSyntaxicalAnalyse()
{
    // analyse syntaxique : analyseur ascendant

    // push state 0
    states.push_front(current_state);
    current_symbole = getNext();

    current_state->transition(*this, current_symbole);

    if (syntaxeChecked)
    {
        // récupérer le programme en haut de la pile
        cout << "LA SYNTAXE EST TIP TOP <3" << endl;
        programme = (Programme*) symboles.front();
    }
    else
    {
        cout << "# Erreur pendant l'analyse !" << endl;
    }

}
void Automate::executeAll()
{
    executeAffichage();
    executeAnalyse();
    executeOptimisation();
    executeExecution();
}

void Automate::executeAffichage()
{
    if (syntaxeChecked)
    {
        cout << *programme;
    }
    // Affichage des map de constantes et de variables (sous forme de code) --> var x; var y; const n = 3; const m = 12;
}

/**
 * Analyse sémantique
 */
void Automate::executeAnalyse()
{
    if (!this->analyse)
    {
        cout << "# Warning : l'analyse n'a pas été demandé par l'utilisateur." << endl;
    }

    /**
     * TODO : ajouter un Programme* program dans les attributs qui contient l'ensemble du programme analysé par l'automate ascendant
     * Avec `program`, faire l'analyse sémantique !
     *      -> Faire toutes les déclarations (utiliser les méthodes déjà codées)
     *      -> Faire toutes les instructions :
     *              ** read : s'assurer que la variable a bien été déclarée
     *              ** write : s'assurer que l'expression a bien été déclarée (& instanciée dans le cas d'une variable)
     *              ** opération = : s'assurer que le membre de gauche est bien une variable DECLAREE / s'assurer que tous les membres de droites sont soit des constantes, soit des variables déclarées et instanciées !!
     */
}

/**
 * A faire après l'analyse sémantique
 */
void Automate::executeExecution()
{
    if (!this->execution)
    {
        cout << "# Warning : l'exécution n'a pas été demandé par l'utilisateur." << endl;
    }
    

    BlocInstruction* blocInstruction = (this->programme)->getBlocInstruction() ;
    deque<Instruction*> liste_instruction = blocInstruction->getListeInstruction();

    for(auto const &it:liste_instruction){
       Affectation *aff = dynamic_cast<Affectation*> (it);
       if(aff != NULL){
            aff->getExpression()->print(cout);
       }
        
    }

   

    cout<<"Nombre d'instructions = "<< liste_instruction.size() << endl;
        
}

/**
 * Optionnel : à faire après analyse syntaxique / sémantique / exécution / affichage
 */
void Automate::executeOptimisation()
{
    if (!this->optimisation)
    {
        cout << "# Warning : l'optimisation n'a pas été demandé par l'utilisateur." << endl;
    }

    // TODO
    // construire la map (ident, val) avant de l'envoyer à eval
}

Symbole* Automate::getNext()
{
    return this->lexer.getNext(this->buffer);
}

void Automate::displayBuffer()
{
    cout << this->buffer << endl;
}




//  _                                 
// | |       ___  __  __   ___   _ __ 
// | |      / _ \ \ \/ /  / _ \ | '__|
// | |___  |  __/  >  <  |  __/ | |   
// |_____|  \___| /_/\_\  \___| |_|   

Lexer::Lexer()
{

}

Lexer::~Lexer()
{

}

string Lexer::regex[] = {"^const$", "^var$", "^lire$", "^ecrire$", ";", "\\(", "\\)", ":=", "=", "\\+", "\\-", "\\*", "\\/", "\\,", "^\\d*$","(?!(^var$|^const$|^ecrire$|^lire$))^[a-zA-Z][a-zA-Z0-9]*$"};

Symbole* Lexer::getNext(string& buff)
{
    
    if (buff.empty())
    {
        return new Symbole(ID_SYMBOLE::dollar); // symbole DOLLAR / EOF
    }

    stringstream flux(buff);
    string buffer = "";
    bool match_flag = false;
    bool error = false;
    bool last_was_no_pattern = false;
    int no_pattern_sequence = 0;
    int id = -1;

    while (!flux.fail())
    {
        char character = (char)flux.peek(); // prochain caractère
        bool stoping_char = false;
        //cout << "BUFFER : " << buffer << " (next character : " << character << ") / no pattern sequence : " << no_pattern_sequence << " !" << endl; // état du buffer

        // TODO : gérer le :=

        // caractère arrêt ?
        switch (character)
        {
            case ' ':
            case ';':
            case '+':
            case '-':
            case '/':
            case '*':
            case ',':
            case '(':
            case ')':
                stoping_char = true;
            break;

            default:

            break;
        }

        if (stoping_char)
        {
            // * si tout seul dans le buffer [buffer vide] (buffer == caractère arrêt)
            if (buffer.empty())
            {
                flux.get();
                // -> si espace
                if (character == ' ')
                {
                    continue;
                }
                // -> sinon
                buffer = character;
                break; // return buffer;
            }

            // * sinon
            // -> si espace
            if (character == ' ')
            {
                flux.get();
            }
            // -> sinon
            break; // return buffer;
        }

        // - si pas caractère arrêt
        string new_buff = buffer + character;

        // test des regex
        bool matched = false;
        for (unsigned int i = 0; i < NB_REGEX; ++i)
        {
            boost::regex re(Lexer::regex[i].c_str());
            boost::cmatch matches;
            bool match = boost::regex_match(new_buff.c_str(), matches, re);
            if (match)
            {
		id = i;
                matched = true;
                break;
            }
        }

        //cout << "NEW BUFF : " << new_buff << " / matched ? " << ((matched) ? "yes" : "no") << endl;
        if (matched)
        {
            flux.get();
            match_flag = true;
            buffer = new_buff;
            last_was_no_pattern = false;
            continue;
        }
        else
        {
            if (match_flag)
            {
                break; // return buffer;
            }

            // Aucun pattern trouvé, on continue pour voir si un pattern va apparaître
            if (last_was_no_pattern)
            {
                no_pattern_sequence++;
            }
            else
            {
                last_was_no_pattern = true;
                no_pattern_sequence = 1;
            }

            if (no_pattern_sequence >= MAX_NO_PATTERN_SEQUENCE)
            {
                error = true;
                break;
            }

            buffer = new_buff;
            flux.get();
        }
    } // fin du while

    // mise à jour du buffer dans l'automate
    getline(flux, buff);

    if (error)
    {
        //return "Erreur - aucun pattern trouvé dans les " + std::to_string(MAX_NO_PATTERN_SEQUENCE) + " derniers caractères.";
	   return NULL;
    }

    Symbole* retour = NULL;

    //cout << "Valeur du symbole lu : " << buffer << "(ID : " << id << ")" << endl;

    switch(id)
    {
    	case -1:
            if (buffer == ";")
            {
                retour = new Symbole(ID_SYMBOLE::pv);
            }
            else if (buffer == "+")
            {
                retour = new Symbole(ID_SYMBOLE::add); 
            }
            else if (buffer == "-")
            {
                retour = new Symbole(ID_SYMBOLE::moins);
            }
            else if (buffer == "/")
            {
                retour = new Symbole(ID_SYMBOLE::divise);
            }
            else if (buffer == "*")
            {
                retour = new Symbole(ID_SYMBOLE::fois);
            }
            else if (buffer == ",")
            {
                retour = new Symbole(ID_SYMBOLE::v);
            }
            else if (buffer == "(")
            {
                retour = new Symbole(ID_SYMBOLE::po);
            }
            else if (buffer == ")")
            {
                retour = new Symbole(ID_SYMBOLE::pf);
            }
            else
            {
                // error
            }
    	break;
    	case 0:
    	    retour = new Symbole(ID_SYMBOLE::ct);
    	break;
    	case 1:
    	    retour = new Symbole(ID_SYMBOLE::va);
    	break;
    	case 2:
    	    retour = new Symbole(ID_SYMBOLE::r);
    	break;
    	case 3:
    	    retour = new Symbole(ID_SYMBOLE::w);
    	break;
    	case 4:
    	    retour = new Symbole(ID_SYMBOLE::pv);
    	break;
    	case 5:
    	    retour = new Symbole(ID_SYMBOLE::po);
    	break;
    	case 6:
    	    retour = new Symbole(ID_SYMBOLE::pf);
    	break;
    	case 7:
    	    retour = new Symbole(ID_SYMBOLE::af);
    	break;
    	case 8:
    	    retour = new Symbole(ID_SYMBOLE::eg);
    	break;
    	case 9:
    	    retour = new Symbole(ID_SYMBOLE::add);
    	break;
    	case 10:
    	    retour = new Symbole(ID_SYMBOLE::moins);
    	break;
    	case 11:
    	    retour = new Symbole(ID_SYMBOLE::fois);
    	break;
    	case 12:
    	    retour = new Symbole(ID_SYMBOLE::divise);
    	break;
    	case 13:
    	    retour = new Symbole(ID_SYMBOLE::v);
    	break;
    	case 14:
    	{
    		// convertir buffer -> int
    		int num;
    		istringstream iss(buffer);
    		iss >> num;
    		retour = new Num(num);
    	}
    	break;
    	case 15:
            retour = new Identificateur(buffer);
    	break;
    	default:
            // error
    	break;
    }

    //cout << " --> Lecture d'un symbole : " << *retour << endl;

    return retour;


        /**
         * /!\ Implémentation légèrement différente de l'algo décrit ci-dessous avec l'intégration du ":=" qui a nécessité d'ajouter un compteur "no_pattern_sequence" pour tolérer le fait qu'on ne rencontre aucun pattern par moment (e.g quand on reçoit ":")
         * TODO :
         *      - si caractère arrêt
         *          * si tout seul dans le buffer [buffer vide] (buffer == caractère arrêt)
         *              -> si pas espace => flux.get() && retourner le symbole
         *              -> si espace => flux.get() et continuer
         *          * si pas tout seul dans le buffer (c'est le symbole d'encore après, [opti : on pourrait le save])
         *              -> si carac_arret == espace => flux.get() et retour du buffer
         *              -> si carac_arret == pas espace => retour du buffer
         *      - si pas caractère arrêt => ajouter caractère au buffer [new_buff]
         *          * tester new_buff sur chaque regex
         *              -> si match => flux.get() mettre un flag à match et continue
         *              -> si non match
                            ** si flag à match => retourner buffer (/!\ pas new_buff)
         *                  ** si flag à non match => retourner erreur (aucun pattern trouvé)
         *
         */
       
}
