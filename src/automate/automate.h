#if !defined ( AUTOMATE_H )
#define AUTOMATE_H

#include "../config.h"
#include "../symbole/symbole.h"
#include "../symbole/programme.h"
#include "../etat/etat.h"
#include <string>
#include <map>
#include <deque>
#include <set>
using namespace std;

//class Etat;

#define NB_REGEX 16
#define MAX_NO_PATTERN_SEQUENCE 10

struct variable_s {
    int value;
    bool instanciated;
};

struct constante_s {
    int value;
};

typedef map<const string, variable_s> map_var;
typedef map<const string, constante_s> map_const;

// enum INSTRUCTION_TYPES {
//     READ, WRITE, INSTANCIATE, DECLARE_CONST, DECLARE_VAR, OPERATION
// };

// struct instruction_s {
//     INSTRUCTION_TYPES type;
//     vector<Symbole> symboles;
// };

class Lexer
{
    public:
        Lexer();
        ~Lexer();
        Symbole* getNext(string& buff);
        static string regex[];
    private:
        set<Identificateur*> idents;
};


class Automate
{
    public:
        Automate();
        Automate(bool aff, bool ana, bool opti, bool exec, string code);
        ~Automate();
        void displayBuffer();
        void execute(OPTIONS option = CHECKED);
        bool addVariable(Identificateur* const id);
        bool addConstante(const string& name, int value);
        bool instanciateVariable(const string& name, int value);
        void displayMemory();
        void decalage(Symbole* s, Etat* e);
        void reduction(Symbole* s);
        void reduction(int nbSymboles, Symbole* s);
        //string getNext(); 
        Symbole* getNext();
	Symbole* getNthSymbole(int n);

        // manage deque
        void updateState(Etat* e);
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

        // structure de données
        map_var variables;
        map_const constantes;
        set<string> idents;

        // syntaxical
        Etat* current_state;
        Symbole* current_symbole;
        deque<Symbole*> symboles;
        deque<Etat*> states;

        // semantic
        bool isVariableInstanciate(const string& name);
        bool isVariableDeclared(const string& name);
        bool isIdentificateurDeclared(const string& name);

        // Lexer
        string code;
        Lexer lexer;
        string buffer;

        // check
        bool syntaxeChecked;

        Programme* programme;

        void executeAll();
        void executeAffichage();
        void executeAnalyse();
        void executeOptimisation();
        void executeExecution();
        void executeSyntaxicalAnalyse();

        // debug
        void displayState();

};

#endif
