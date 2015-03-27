#if !defined ( MEMORY_H )
#define MEMORY_H

#include <string>
#include <set>
#include <vector>

#include "../symbole/programme.h"
#include "../symbole/declaration/identificateur.h"

struct variable_s {
    int value;
    bool instanciated;
    bool isSemanticInstanciated;
};

struct constante_s {
    int value;
};

typedef map<const string, variable_s> map_var;
typedef map<const string, constante_s> map_const;

class Memory
{
    public:
        // core
        Memory() : programme(NULL) {}
        Memory(Programme* p) : programme(p) {}
        ~Memory();

        // methods related to maps
        bool addVariable(Identificateur* const id);
        bool addConstante(const string& name, int value);
        void semanticInstanciation(const string& name);
        bool instanciateVariable(const string& name, int value);
        bool isVariableSemanticInstanciated(const string& name);
        bool isVariableDeclared(const string& name);
        bool isIdentificateurDeclared(const string& name);
        bool isVariable(const string & name);

        void displayMemory();

        // methods related to programme
        inline vector<Declaration*> getDeclarations() { return programme->getBlocDeclaration()->getListeDeclaration(); }
        inline vector<Instruction*> getInstructions() { return programme->getBlocInstruction()->getListeInstruction(); }


    private:
        // methods

        // data structures
        Programme* programme;
        map_var variables;
        map_const constantes;
        set<string> idents;
};

#endif