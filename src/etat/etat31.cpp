#include "etat31.h"
#include "../config.h"


Etat31::Etat31(string pName) : Etat(pName){}
Etat31::Etat31(){}
Etat31::~Etat31(){}

bool Etat31::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case id :
			//TODO: r23
			break;
		case num :
			//TODO: r23
			break;
		case po :
			//TODO: r23
			break;
		default : break;
	}
	return false;
}

