#if !defined ( AUTOMATE_H )
#define AUTOMATE_H

#include "../config.h"
#include "../symbole/symbole.h"
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
};


class Automate
{
    public:
        Automate();
        Automate(bool aff, bool ana, bool opti, bool exec, string code);
        ~Automate();
        void displayBuffer();
        void execute(OPTIONS option = CHECKED);
        bool addVariable(const string& name);
        bool addConstante(const string& name, int value);
        bool instanciateVariable(const string& name, int value);
        void displayMemory();
        void decalage(Symbole* s, Etat* e);
        void reduction(int nbSymboles, Symbole* s);
        //string getNext(); 
        void updateState(Etat* e);
        Symbole* getNext();


    private:
        // options
        bool affichage;
        bool analyse;
        bool optimisation;
        bool execution;

        // structure de données
        Etat* current_state;
        map_var variables;
        map_const constantes;
        set<string> idents;
        deque<Symbole*> symboles;
        deque<Etat*> states;

        // map<int, instruction_s> instructions;

        // Lexer
        string code;
        Lexer lexer;
        string buffer;

        void executeAll();
        void executeAffichage();
        void executeAnalyse();
        void executeOptimisation();
        void executeExecution();
        void executeSyntaxicalAnalyse();

};

#endif
