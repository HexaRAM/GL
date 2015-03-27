#if !defined ( EXECUTION_H )
#define EXECUTION_H

#include "action.h"

class Execution : public Action
{
    public:
        Execution() : Action() {}
        ~Execution();
        bool execute(Memory& mem);
};

#endif