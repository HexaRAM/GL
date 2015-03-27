#if !defined ( SEMANTIQUE_H )
#define SEMANTIQUE_H

#include "action.h"

class Semantique : public Action
{
    public:
        Semantique() : Action() {}
        ~Semantique();
        bool execute(Memory& mem);
};

#endif