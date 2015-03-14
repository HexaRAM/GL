#include "etat43.h"
#include "etat0.h"
#include "etat1.h"
#include "../config.h"


Etat43::Etat43(string pName) : Etat(pName){}
Etat43::Etat43(){}
Etat43::~Etat43(){}

bool Etat43::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case v :
			//TODO: R6
			break;
		case pv :
			//TODO: R6
			break;
		default : break;
	}
	return false;
}

