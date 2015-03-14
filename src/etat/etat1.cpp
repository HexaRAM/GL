#include "etat1.h"
#include "../config.h"

Etat1::Etat1(string pName) : Etat(pName){}
Etat1::Etat1(){}
Etat1::~Etat1(){}

bool Etat1::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case dollar :
			//accepter
			break;
		default : break;
	}
	return false;
}

