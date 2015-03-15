#include "etat3.h"
#include "../config.h"

Etat3::Etat3(string pName) : Etat(pName){}
Etat3::Etat3(){}
Etat3::~Etat3(){}

bool Etat3::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case I :
			automate.decalage(s, new Etat 7);
			break;
		case id :
			automate.decalage(s, new Etat 8);
			break;
		case r :
			automate.decalage(s, new Etat 9);
			break;
		case w :
			automate.decalage(s, new Etat 10);
			break;
		case dollar :
			//réduction r1 : P -> LD LI
			break;
		default : break;
	}
	return false;
}

