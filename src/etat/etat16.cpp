#include "../config.h"

Etat28::Etat28(string pName) : Etat(pName){}
Etat28::Etat28(){}
Etat28::~Etat28(){}

bool Etat28::transition(Automate & automate, Symbole * s ){
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

