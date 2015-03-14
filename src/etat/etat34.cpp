#include "etat34.h"
#include "../config.h"


Etat34::Etat34(string pName) : Etat(pName){}
Etat34::Etat34(){}
Etat34::~Etat34(){}

bool Etat34::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case id :
			//TODO: R25
			break;
		case num :
			//TODO: R25
			break;
		case po :
			//TODO: R25
			break;
		default : break;
	}
	return false;
}

