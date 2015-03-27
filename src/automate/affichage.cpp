#include "affichage.h"

Affichage::~Affichage()
{

}

bool Affichage::execute(Memory& mem)
{
    mem.displayMemory();
    return true;
}