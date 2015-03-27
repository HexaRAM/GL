#if !defined ( OPTIMISATION_H )
#define OPTIMISATION_H

#include "action.h"
#include "../symbole/declaration/identificateur.h"

class Optimisation : public Action
{
    public:
        Optimisation() : Action() {}
        ~Optimisation();
        bool execute(Memory& mem);
    protected:
    	bool isConst(Identificateur* id, Memory& mem);
};

#endif