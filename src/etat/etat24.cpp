#include "etat24.h"
#include "../config.h"

Etat24::Etat24(string pName) : Etat(pName){}
Etat24::Etat24(){}
Etat24::~Etat24(){}

bool Etat24::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case E :
			automate.decalage(s, new Etat 35);
			break;
		case T :
			automate.decalage(s, new Etat 20);
			break;
		case F :
			automate.decalage(s, new Etat 21);
			break;
		case id :
			automate.decalage(s, new Etat 22);
			break;
		case num :
			automate.decalage(s, new Etat 23);
			break;
		case po:
			automate.decalage(s, new Etat 24);
			break;
		default : break;
	}
	return false;
}

