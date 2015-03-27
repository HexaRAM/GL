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

// struct variable_s {
//     int value;
//     bool instanciated;
//     bool isSemanticInstanciated;
// };

// struct constante_s {
//     int value;
// };

// typedef map<const string, variable_s> map_var;
// typedef map<const string, constante_s> map_const;

// enum INSTRUCTION_TYPES {
//     READ, WRITE, INSTANCIATE, DECLARE_CONST, DECLARE_VAR, OPERATION
// };

// struct instruction_s {
//     INSTRUCTION_TYPES type;
//     vector<Symbole> symboles;
// };

class Automate
{
    public:
        Automate();
        Automate(bool aff, bool ana, bool opti, bool exec, string code);
        ~Automate();
        void displayBuffer();
        void execute(OPTIONS option = CHECKED);

        // semantic à retirer
        bool addVariable(Identificateur* const id);
        bool addConstante(const string& name, int value);
        void semanticInstanciation(const string& name);
        bool instanciateVariable(const string& name, int value);
        void displayMemory();

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


    private:
        // options
        bool affichage;
        bool analyse;
        bool optimisation;
        bool execution;

        // structure de données à retirer
        map_var variables;
        map_const constantes;
        set<string> idents;

        // syntaxical
        Etat* current_state;
        Symbole* current_symbole;
        deque<Symbole*> symboles;
        deque<Etat*> states;
        void updateState(Etat* e);
        Symbole* getNext();

        // semantic à retirer
        bool isVariableSemanticInstanciated(const string& name);
        bool isVariableDeclared(const string& name);
        bool isIdentificateurDeclared(const string& name);
        bool isVariable(const string & name);

        // Lexer
        string code;
        Lexer lexer;
        string buffer;

        // check
        bool syntaxeChecked;

        Programme* programme; // à retirer
        Memory* memory;

        void executeAll();
        void executeAffichage();
        void executeAnalyse();
        void executeOptimisation();
        void executeExecution();
        bool executeSyntaxicalAnalyse();

        // debug
        void displayState();

};

#endif
