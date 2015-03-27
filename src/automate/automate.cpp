#include "automate.h"
#include "../symbole/declaration/num.h"
#include "../symbole/declaration/identificateur.h"
#include <boost/regex.hpp>
#include "../etat/etat0.h"
#include "../symbole/ecriture.h"
#include "../symbole/lecture.h"
#include "../symbole/affectation.h"
#include "../symbole/declaration/declarationVar.h"
#include "../symbole/declaration/declarationConst.h"
#include <vector>

#include "semantique.h"
#include "execution.h"
#include "optimisation.h"
#include "affichage.h"

#include <iostream>
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
    this->memory = NULL;
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
    this->memory = NULL;
}

Automate::~Automate()
{
    // si les piles symboles ou states ne sont pas vides
    // les vider à coup de delete pour ne pas causer de memory leaks

    for (auto *it : states) // contient current_state
    {
        delete it;
    }

    delete current_symbole; // le symbole $ est resté en mémoire

    // les symboles restants sont dans Memory
    delete memory; // todo : destruction dans les classes symboles
}

/**
 * Public methods
 */
bool Automate::addVariable(Identificateur* const id)
{
    string name = (string)(*id);

    if (this->idents.find(name) != this->idents.end())
    {
        // var already exists
        cout << "# L'identificateur `" << name << "` a déjà été utilisé par une autre variable/constante." << endl;
        return false;
    }
    else
    {

        // var doesn't exist
        this->variables[name] = {-1, false, false};
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

// only var
bool Automate::isVariableSemanticInstanciated(const string& name)
{
    map_var::iterator it = this->variables.find(name);

    if (it == this->variables.end())
    {
        // variable `name` doesn't exist
        cout << "# La variable " << name << " n'existe pas." << endl;
        return false;
    }

    return it->second.isSemanticInstanciated;
}

// only var
bool Automate::isVariableDeclared(const string& name)
{
    if (this->variables.find(name) != this->variables.end())
    {
        return true;
    }
    return false;
}

// const or var
bool Automate::isIdentificateurDeclared(const string& name)
{
    if (this->idents.find(name) != this->idents.end())
    {
        return true;
    }
    return false;
}

bool Automate::isVariable(const string& name)
{
    if (this->variables.find(name) != this->variables.end())
    {
        return true;
    }
    return false;
}

void Automate::semanticInstanciation(const string& name)
{
    if (this->idents.find(name) == this->idents.end())
    {
        // idents `name` doesn't exist
        cout << "# La variable " << name << " n'existe pas." << endl;
        return;
    }

    map_var::iterator it = variables.find(name);

    if (it == variables.end())
    {
        // var doesn't exist
        cout << "# La variable " << name << " n'existe pas." << endl;
        return;
    }

    // var exist
    it->second.isSemanticInstanciated = true;
}

bool Automate::instanciateVariable(const string& name, int value)
{

    #ifdef DEBUG
        cout << "On affecte " << value << " à la variable " << name << endl;
    #endif

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

    // si on ne précise pas de valeur (-1 est la valeur par défaut, on n'ajoute pas la valeur dans la map) => pour que l'analyse sémantique n'ait pas à tout détruire pour effectuer ses tests.
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
        cout << ")";

        if (it.second.isSemanticInstanciated)
        {
            cout << " but semantic instanciated !";
        }
        cout << endl;
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
    #ifdef DEBUG
        cout << "\t-> Décalage " << *e << endl;
    #endif
    symboles.push_front(s);
    this->updateState(e);
    current_symbole = getNext();

    this->displayState();

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

    this->displayState();

    current_state->transition(*this, current_symbole);
}


/**
 * réduction avec dépilement automatique
 */
void Automate::reduction(int nbSymboles, Symbole* newSymbole)
{
    #ifdef DEBUG
        cout << "\t-> Réduction : création de " << *newSymbole << " (nbSymboles=" << nbSymboles << ")" << endl;
    #endif

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

/**
 * Obtenir un symbole de la pile (utilisée lors des réductions)
 */
Symbole* Automate::getNthSymbole(int n)
{
	return symboles[n];
}

/**
 * Valider la syntaxe - Cette fonction évite de devoir remonter tous les bool pour savoir si la syntaxe du fichier est bonne ou non
 */
void Automate::validateSyntaxe()
{
    syntaxeChecked = true;
}

void Automate::execute(OPTIONS option)
{

    // analyse syntaxique
    bool ok = executeSyntaxicalAnalyse();

    if (!ok)
    {
        cerr << "# Erreur pendant l'analyse syntaxique !" << endl;
        cerr << "Il restait `" << buffer << "` à analyser" << endl;
        exit(1);
    }
    cout << "LA SYNTAXE EST TIP TOP <3" << endl;

    switch (option)
    {
        case ALL:
            executeAll();
        break;

        case CHECKED:

            if (this->analyse)
            {
                // analyse statique (-a)
                executeAnalyse();
            }



            if (this->optimisation)
            {
                // optimisation (-o)
                // modifier directement les instructions
                executeOptimisation();
            }

            if (this->affichage)
            {
                // affiche le programme (-p) [optimisé si -o]
                executeAffichage();
            }

            if (this->execution)
            {
                // execute le programme (-e)
                if (!this->analyse)
                {
                    // inutile d'exécuter le programme si la sémantique n'est pas bonne
                    executeAnalyse();
                }
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
            #ifdef DEBUG
                cout << "# Error : option inconnue demandée." << endl;
            #endif
        break;
    }
}

bool Automate::executeSyntaxicalAnalyse()
{
    // analyse syntaxique : analyseur ascendant

    // push state 0
    states.push_front(current_state);
    current_symbole = getNext();

    current_state->transition(*this, current_symbole);

    if (syntaxeChecked)
    {
        // récupérer le programme en haut de la pile
        Programme* programme = (Programme*) symboles.front();
        this->programme = programme; // à retirer
        Memory* mem = new Memory(programme);
        this->memory = mem;
        return true;
    }
    return false;
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
    Affichage a;
    bool ok = a.execute(*memory);

    if (!ok)
    {
        cerr << "Une erreur s'est produite pendant l'affichage de la mémoire. Fermeture du programme." << endl;
        exit(1);
    }
    cout << "L'AFFICHAGE EST TIP TOP <3" << endl;
}

void Automate::executeAnalyse()
{
    Semantique s;
    bool ok = s.execute(*memory);

    if (!ok)
    {
        cerr << "Une erreur s'est produite pendant l'analyse sémantique. Fermeture du programme." << endl;
        exit(1);
    }
    cout << "LA SEMANTIQUE EST TIP TOP <3" << endl;
}

/**
 * Execution du programme. Celui-ci doit d'abord avoir été validé syntaxiquement et sémantiquement
 */
void Automate::executeExecution()
{
    Execution e;
    bool ok = e.execute(*memory);

    if (!ok)
    {
        cerr << "Une erreur s'est produite pendant l'exécution. Fermeture du programme." << endl;
        exit(1);
    }
    cout << "L'EXECUTION EST TIP TOP <3" << endl;        
}

/**
 * Optionnel : à faire après analyse syntaxique / sémantique / exécution / affichage
 */
void Automate::executeOptimisation()
{
    Optimisation o;
    bool ok = o.execute(*memory);

    if (!ok)
    {
        cerr << "Une erreur s'est produite pendant l'optimisation. Fermeture du programme." << endl;
        exit(1);
    }
    cout << "L'OPTIMISATION EST TIP TOP <3" << endl;

    /**
     * TODO :
     * - Refactor complet des classes, plus besoin de faire un getAffectationsConstants() ici, tout se passe dans la classe Memory (pour la gestion du programme)
     * - Votre portion de code se trouve dans la classe "Optimisation", fichier "optimisation.h/cpp"
     */
}

Symbole* Automate::getNext()
{
    return lexer.getNext(this->buffer);
}

void Automate::displayBuffer()
{
    cout << this->buffer << endl;
}
