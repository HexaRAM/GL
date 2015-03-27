#if !defined ( ACTION_H )
#define ACTION_H

#include "memory.h"

class Action
{
    public:
        Action();
        ~Action();
        virtual bool execute(Memory& mem) = 0;
};

#endif