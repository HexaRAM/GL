#include "etat14.h"
#include "../config.h"

Etat14::Etat14(string pName) : Etat(pName){}
Etat14::Etat14(){}
Etat14::~Etat14(){}

bool Etat14::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case v :
			//automate.decalage(s, new Etat 27);
			break;
		case pv :
			//Reduction r5 : D -> va V
			break;
		default : break;
	}
	return false;
}

