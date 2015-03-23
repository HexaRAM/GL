#include "etat.h"
#include <iostream>
using namespace std;

Etat::Etat(string pName) : name(pName){}
Etat::Etat(){}
Etat::~Etat(){}

ostream& operator<<(ostream& os, const Etat& e)
{
    os << e.name;
    return os;
}