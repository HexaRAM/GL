#include "etat27.h"
#include "etat38.h"
#include "../config.h"

Etat27::Etat27(string pName) : Etat(pName){}
Etat27::Etat27(){}
Etat27::~Etat27(){}

bool Etat27::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case id :
			automate.decalage(s, new Etat 38);
			break;
		default : break;
	}
	return false;
}

