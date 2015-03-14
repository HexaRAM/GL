#include "etat33.h"
#include "../config.h"


Etat33::Etat33(string pName) : Etat(pName){}
Etat33::Etat33(){}
Etat33::~Etat33(){}

bool Etat33::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case id :
			//TODO: R24
			break;
		case num :
			//TODO: R24
			break;
		case po :
			//TODO: R24
			break;
		default : break;
	}
	return false;
}

