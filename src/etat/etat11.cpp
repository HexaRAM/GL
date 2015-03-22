#include "etat11.h"
#include "../config.h"
#include "../symbole/declaration/blocDeclaration.h"

Etat11::Etat11(string pName) : Etat(pName){}
Etat11::Etat11(){}
Etat11::~Etat11(){}

bool Etat11::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case ct :
		case va :
		case dollar :
		{
			//Reduction r2 : LD -> LD D pv
			int nbSymboles = 3;
			Symbole* s= new BlocDeclaration();
			automate.reduction(nbSymboles,s);
			break;
		}
		default : break;
	}
	return false;
}

