#include "etat37.h"
#include "../config.h"


Etat37::Etat37(string pName) : Etat(pName){}
Etat37::Etat37(){}
Etat37::~Etat37(){}

bool Etat37::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case v :
			//TODO: r7
			break;
		case pv :
			//TODO: r7
			break;
		default : break;
	}
	return false;
}

