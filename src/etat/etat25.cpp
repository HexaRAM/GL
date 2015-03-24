#include "etat25.h"
#include "etat36.h"
#include "../config.h"

Etat25::Etat25(string pName) : Etat(pName){}
Etat25::Etat25(){}
Etat25::~Etat25(){}

bool Etat25::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case id :
			automate.decalage(s, new Etat36("36"));
			break;
		default : break;
	}
	return false;
}

