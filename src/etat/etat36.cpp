#include "etat36.h"
#include "etat42.h"
#include "../config.h"


Etat36::Etat36(string pName) : Etat(pName){}
Etat36::Etat36(){}
Etat36::~Etat36(){}

bool Etat36::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case eg :
			automate.decalage(s, new Etat42("42"));
			break;
		default : break;
	}
	return false;
}

