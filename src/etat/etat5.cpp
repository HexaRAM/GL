#include "etat5.h"
#include "../config.h"

Etat5::Etat5(string pName) : Etat(pName){}
Etat5::Etat5(){}
Etat5::~Etat5(){}

bool Etat5::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case C :
			automate.decalage(s, new Etat 12);
			break;
		case id :
			automate.decalage(s, new Etat 13);
			break;
		default : break;
	}
	return false;
}

