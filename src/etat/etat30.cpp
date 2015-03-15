#include "etat30.h"
#include "../config.h"


Etat30::Etat30(string pName) : Etat(pName){}
Etat30::Etat30(){}
Etat30::~Etat30(){}

bool Etat30::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case id :
			//TODO: r22
			break;
		case num :
			//TODO: r22
			break;
		case po :
			//TODO: r22
			break;
		default : break;
	}
	return false;
}

