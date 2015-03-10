#if !defined ( AUTOMATE_H )
#define AUTOMATE_H

#include "../config.h"
#include "../symbole/symbole.h"
#include <string>
#include <map>
#include <set>
using namespace std;

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
        //Symbole getNext(const string& code); // en attendant les classes Symboles
        string getNext(string& buff);
        static string regex[];
    private:
};


class Automate
{
    public:
        Automate();
        Automate(bool aff, bool ana, bool opti, bool exec, string code);
        virtual ~Automate() {}
        void displayBuffer();
        void execute(OPTIONS option = ALL);
        bool addVariable(const string& name);
        bool addConstante(const string& name, int value);
        bool instanciateVariable(const string& name, int value);
        void displayMemory();
        string getNext();

    private:
        bool affichage;
        bool analyse;
        bool optimisation;
        bool execution;
        map_var variables;
        map_const constantes;
        set<string> idents;
        // map<int, instruction_s> instructions;
        string code;
        Lexer lexer;
        string buffer;

        void executeAll();
        void executeAffichage();
        void executeAnalyse();
        void executeOptimisation();
        void executeExecution();

};

#endif