#if !defined ( AUTOMATE_H )
#define AUTOMATE_H

#include "../config.h"
#include "lexer.h"
#include "../symbole/symbole.h"
#include "../symbole/programme.h"
#include "../etat/etat.h"
#include "memory.h"
#include <string>
#include <map>
#include <deque>
#include <set>
using namespace std;

//class Etat;

#define NB_REGEX 16
#define MAX_NO_PATTERN_SEQUENCE 10

class Automate
{
    public:
        Automate();
        Automate(bool aff, bool ana, bool opti, bool exec, string code, vector<int> linesBreaks);
        ~Automate();

        // syntaxic
        void decalage(Symbole* s, Etat* e);
        void reduction(Symbole* s);
        void reduction(int nbSymboles, Symbole* s); 
	    Symbole* getNthSymbole(int n);

        // manage deque
        void popSymbole();
        void popState();
        void popAndDeleteState();
        void popAndDeleteSymbole();

        void validateSyntaxe();

        // execute option
        void execute(OPTIONS option = CHECKED);


    private:
        // options
        bool affichage;
        bool analyse;
        bool optimisation;
        bool execution;

        // syntaxical
        Etat* current_state;
        Symbole* current_symbole;
        deque<Symbole*> symboles;
        deque<Etat*> states;
        void updateState(Etat* e);
        Symbole* getNext();

        // Lexer
        Lexer lexer;
        string code;
        string buffer;

        // check
        bool syntaxeChecked;

        // memory manager
        Memory* memory;

        // line management
        vector<int> linesBreaks;

        // execute functions
        bool executeSyntaxicalAnalyse();
        void executeAll();
        void executeAffichage();
        void executeAnalyse();
        void executeOptimisation();
        void executeExecution();

        // debug
        void displayState();

};

#endif
