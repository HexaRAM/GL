#include "etat22.h"
#include "../config.h"

Etat22::Etat22(string pName) : Etat(pName){}
Etat22::Etat22(){}
Etat22::~Etat22(){}

bool Etat22::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case pf :
		case add :
		case moins :
		case fois :
		case divise :
			//Reduction r19 : F -> id
			break;
		default : break;
	}
	return false;
}

