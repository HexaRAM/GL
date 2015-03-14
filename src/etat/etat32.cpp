#include "etat32.h"
#include "etat40.h"
#include "../config.h"


Etat32::Etat32(string pName) : Etat(pName){}
Etat32::Etat32(){}
Etat32::~Etat32(){}

bool Etat32::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case id :
			//TODO: R22
			break;
		case num :
			//TODO: R23
			break;
		case po :
			//TODO: R24
			break;
		case F :
			automate.decalage(s, new Etat40);
			break;
		default : break;
	}
	return false;
}

