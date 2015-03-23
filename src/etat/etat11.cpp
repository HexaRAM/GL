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
			Declaration* dec = (Declaration*) automate.getNthSymbole(1);
			BlocDeclaration* blocDec = (BlocDeclaration*) automate.getNthSymbole(2);
			blocDec->addDeclaration(dec);
			automate.reduction(nbSymboles,blocDec);
			break;
		}
		default : break;
	}
	return false;
}

