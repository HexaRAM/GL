#include "../config.h"
#include "etat16.h"

Etat16::Etat16(string pName) : Etat(pName){}
Etat16::Etat16(){}
Etat16::~Etat16(){}

bool Etat16::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case id :
		case r :
		case w : 
		case dollar :
			// TODO r10
			break;
		
		default : break;
	}
	return false;
}

