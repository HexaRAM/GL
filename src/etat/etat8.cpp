#include "etat8.h"
#include "etat15.h"
#include "etat17.h"
#include "../config.h"

Etat8::Etat8(string pName) : Etat(pName){}
Etat8::Etat8(){}
Etat8::~Etat8(){}

bool Etat8::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case af :
			automate.decalage(s, new Etat17("17"));
		break;
		default :
            automate.recuperation(new Symbole(107), true); // on est sûr qu'il manque un :=
        break;
	}
	return false;
}

