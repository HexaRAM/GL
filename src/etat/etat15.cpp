#include "etat15.h"
#include "../config.h"

Etat15::Etat15(string pName) : Etat(pName){}
Etat15::Etat15(){}
Etat15::~Etat15(){}

bool Etat15::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case v :
		case pv :
			//Reduction r9 : V -> id
			break;
		default : break;
	}
	return false;
}

