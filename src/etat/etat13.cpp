#include "etat13.h"
#include "etat26.h"
#include "../config.h"

Etat13::Etat13(string pName) : Etat(pName){}
Etat13::Etat13(){}
Etat13::~Etat13(){}

bool Etat13::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case eg :
			automate.decalage(s, new Etat26);
			break;
		default : break;
	}
	return false;
}

