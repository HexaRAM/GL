#include "automate.h"
#include <iostream>
#include <boost/regex.hpp>
using namespace std;

/**
 * TODO : retirer tous les commentaires sur les lignes utilisant les états une fois que les classes états seront implémentées
 */

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
    //this->current_state = new Etat0;
    this->current_state = NULL;
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
    //this->current_state = new Etat0;
    this->current_state = NULL;
}

Automate::~Automate()
{
    //delete current_state;

    // si les piles symboles ou states ne sont pas vides
    // les vider à coup de delete pour ne pas causer de memory leaks
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
        cout.flush();
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
void Automate::decalage(Symbole* s, Etat* e){
    // TODO
}

// void Automate::reduction(Symbole symboleGauche, int nbSymbolesDroite){
//     // TODO
// }

void Automate::executeSyntaxicalAnalyse()
{
    // analyse syntaxique : analyseur ascendant

    bool keepGoing = true;

    // push state 0
    // states.push_front(current_state);

    while (keepGoing)
    {
        // Symbole* nextSymbole = getNext();
        // keepGoing = init->transition(*this, nextSymbole);
        keepGoing = false; // TODO : remove this line
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
    if (!this->affichage)
    {
        cout << "# Warning : l'affichage n'a pas été demandé par l'utilisateur." << endl;
    }

    cout << code << endl;

    // TODO
}

void Automate::executeAnalyse()
{
    if (!this->analyse)
    {
        cout << "# Warning : l'analyse n'a pas été demandé par l'utilisateur." << endl;
    }

    // TODO
}

void Automate::executeOptimisation()
{
    if (!this->optimisation)
    {
        cout << "# Warning : l'optimisation n'a pas été demandé par l'utilisateur." << endl;
    }

    // TODO
}

void Automate::executeExecution()
{
    if (!this->execution)
    {
        cout << "# Warning : l'exécution n'a pas été demandé par l'utilisateur." << endl;
    }

    // TODO
    // construire la map (ident, val) avant de l'envoyer à eval
}
string Automate::getNext()
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

string Lexer::getNext(string& buff)
{
    if (buff.empty())
    {
        return "$"; // symbole DOLLAR / EOF
    }

    stringstream flux(buff);
    string buffer = "";
    bool match_flag = false;
    bool error = false;
    bool last_was_no_pattern = false;
    int no_pattern_sequence = 0;

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
        return "Erreur - aucun pattern trouvé dans les " + std::to_string(MAX_NO_PATTERN_SEQUENCE) + " derniers caractères.";
    }

    return buffer;

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