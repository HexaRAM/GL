#include "etat11.h"
#include "../config.h"

Etat11::Etat11(string pName) : Etat(pName){}
Etat11::Etat11(){}
Etat11::~Etat11(){}

bool Etat11::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case ct :
		case va :
		case dollar :
			//Reduction r2 : LD -> LD D pv
			break;
		default : break;
	}
	return false;
}

