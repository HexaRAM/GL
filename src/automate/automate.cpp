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

/**
 * core class
 */
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
    this->isInRecuperation = false;
    this->memory = NULL;
    this->nextSymboleRecup = NULL;
}

Automate::Automate(bool affichage, bool analyse, bool optimisation, bool execution, string code, vector<int> linesBreaks)
{
    this->affichage = affichage;
    this->analyse = analyse;
    this->optimisation = optimisation;
    this->execution = execution;

    this->code = code;
    this->buffer = code;
    this->lexer = Lexer(linesBreaks);

    this->current_state = new Etat0("0");
    this->current_symbole = NULL;

    this->isInRecuperation = false;
    this->syntaxeChecked = false;
    this->memory = NULL;
    this->nextSymboleRecup = NULL;
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
    delete memory;
}




/**
 * Manage deque
 */
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



/**
 * Analyseur
 */

/**
 * Obtenir le prochain symbole sous la tête de lecture
 */
Symbole* Automate::getNext()
{
    if (this->isInRecuperation)
    {
        this->isInRecuperation = false;
        return nextSymboleRecup;
    }
    return lexer.getNext(this->buffer);
}
void Automate::decalage(Symbole* s, Etat* e)
{
    #ifdef DEBUG
        cout << "\t-> Décalage " << *e << endl;
    #endif
    symboles.push_front(s);
    this->updateState(e);

    current_symbole = getNext();

    if (current_symbole == NULL)
    {
        #ifdef DEBUG
            cout << "Symbole inconnu sous la tête de lecture !" << endl;
        #endif
        exit(1);
    }

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
 * TODO
 * Récupérer un symbole non lu par un symbole "attendu". Quand plusieurs symboles peuvent être présent. On fait une hypothèse sur le symbole le plus probable.
 * OPTI : vector<Symbole*> symbolesToRecup et boucler tant qu'on ne trouve pas de symbole qui va bien
 */

void Automate::recuperation(Symbole* symboleToRecup, bool sureSymboleToRecupIsTheOneExpected)
{
    // current_symbole contient le prochain symbole (on doit le conserver)
    // symboleToRecup est le symbole à mettre à la place du symbole manquant

    string symboleOrOperator = "symbole";
    if (Symbole::isOperator(symboleToRecup))
    {
        symboleOrOperator = "operateur";
    }

    cerr << "Erreur syntaxique (" << lexer.getLine() << ":" << lexer.getColumn() << ") " << symboleOrOperator << " " << *symboleToRecup << " " << ((sureSymboleToRecupIsTheOneExpected) ? "" : "probablement ")<< "attendu" << endl;

    this->isInRecuperation = true;
    this->nextSymboleRecup = this->current_symbole; // sauvegarde du current symbole
    this->current_symbole = symboleToRecup; // on insère le symbole de récupération

    // OPTI : en théorie, boucler tant que c'est pas ok sur l'ensemble des symboles possibles pour la récupération

    bool ok = current_state->transition(*this, current_symbole);
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


/**
 * Execute functions
 */
void Automate::execute(OPTIONS option)
{

    // analyse syntaxique
    bool ok = executeSyntaxicalAnalyse();

    if (!ok)
    {
        #ifdef DEBUG
            cout << "# Erreur pendant l'analyse syntaxique !" << endl;
            cout << "Il restait `" << buffer << "` à analyser" << endl;
        #endif
        exit(1);
    }
    #ifdef DEBUG
        cout << "LA SYNTAXE EST TIP TOP <3" << endl;
    #endif

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
                if (!this->analyse)
                {
                    // inutile d'optimiser le programme si la sémantique n'est pas bonne
                    this->analyse = true;
                    executeAnalyse();
                }
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
                    this->analyse = true;
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

    if (current_symbole == NULL)
    {
        #ifdef DEBUG
            cout << "Symbole inconnu sous la tête de lecture !" << endl;
        #endif
        exit(1);
    }

    current_state->transition(*this, current_symbole);

    if (syntaxeChecked)
    {
        // récupérer le programme en haut de la pile
        Programme* programme = (Programme*) symboles.front();
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
        //cerr << "Une erreur s'est produite pendant l'affichage de la mémoire. Fermeture du programme." << endl;
        exit(1);
    }
    #ifdef DEBUG
        cout << "L'AFFICHAGE EST TIP TOP <3" << endl;
    #endif
}

void Automate::executeAnalyse()
{
    Semantique s;
    bool ok = s.execute(*memory);

    if (!ok)
    {
        //cerr << "Une erreur s'est produite pendant l'analyse sémantique. Fermeture du programme." << endl;
        exit(1);
    }
    #ifdef DEBUG
        cout << "LA SEMANTIQUE EST TIP TOP <3" << endl;
    #endif
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
        //cerr << "Une erreur s'est produite pendant l'exécution. Fermeture du programme." << endl;
        exit(1);
    }
    #ifdef DEBUG
        cout << "L'EXECUTION EST TIP TOP <3" << endl; 
    #endif       
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
        //cerr << "Une erreur s'est produite pendant l'optimisation. Fermeture du programme." << endl;
        exit(1);
    }
    #ifdef DEBUG
        cout << "L'OPTIMISATION EST TIP TOP <3" << endl;
    #endif
}

/**
 * Debug methods
 */
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
