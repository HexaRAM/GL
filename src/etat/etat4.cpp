#include "etat4.h"
#include "../config.h"

Etat4::Etat4(string pName) : Etat(pName){}
Etat4::Etat4(){}
Etat4::~Etat4(){}

bool Etat4::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case pv :
			automate.decalage(s, new Etat 11);
			break;
		default : break;
	}
	return false;
}

