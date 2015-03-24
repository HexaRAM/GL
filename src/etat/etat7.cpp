#include "etat7.h"
#include "etat16.h"
#include "../config.h"

Etat7::Etat7(string pName) : Etat(pName){}
Etat7::Etat7(){}
Etat7::~Etat7(){}

bool Etat7::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case pv :
			automate.decalage(s, new Etat16("16"));
			break;
		default : break;
	}
	return false;
}

