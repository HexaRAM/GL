#include "etat9.h"
#include "etat18.h"
#include "../config.h"

Etat9::Etat9(string pName) : Etat(pName){}
Etat9::Etat9(){}
Etat9::~Etat9(){}

bool Etat9::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case id :
			automate.decalage(s, new Etat18("18"));
			break;
		default : break;
	}
	return false;
}

