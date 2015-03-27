#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "action.h"

class Affichage : public Action
{
    public:
        Affichage() : Action() {}
        ~Affichage();
        bool execute(Memory& mem);
};

#endif