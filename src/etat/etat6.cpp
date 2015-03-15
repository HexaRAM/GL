#include "etat6.h"
#include "../config.h"

Etat6::Etat6(string pName) : Etat(pName){}
Etat6::Etat6(){}
Etat6::~Etat6(){}

bool Etat6::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case V :
			automate.decalage(s, new Etat 14);
			break;
		case id :
			automate.decalage(s, new Etat 15);
			break;
		default : break;
	}
	return false;
}

