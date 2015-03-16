#include "etat18.h"
#include "../config.h"

Etat18::Etat18(string pName) : Etat(pName){}
Etat18::Etat18(){}
Etat18::~Etat18(){}

bool Etat18::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case pv :
			//TODO : r13
			break;
		default : break;
	}
	return false;
}

