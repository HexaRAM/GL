#include "etat26.h"
#include "etat37.h"
#include "../config.h"

Etat26::Etat26(string pName) : Etat(pName){}
Etat26::Etat26(){}
Etat26::~Etat26(){}

bool Etat26::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case num :
			automate.decalage(s, new Etat37("37"));
			break;
		default : break;
	}
	return false;
}

