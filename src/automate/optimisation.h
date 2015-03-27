#if !defined ( OPTIMISATION_H )
#define OPTIMISATION_H

#include "action.h"

class Optimisation : public Action
{
    public:
        Optimisation() : Action() {}
        ~Optimisation();
        bool execute(Memory& mem);
};

#endif