#include "etat37.h"
#include "../config.h"
#include "../symbole/declaration/declarationConst.h"


Etat37::Etat37(string pName) : Etat(pName){}
Etat37::Etat37(){}
Etat37::~Etat37(){}

bool Etat37::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case v :
		case pv :
		{
			//Regle R7 : C → id eg num
			int nbSymboles = 3;
			Symbole* s= new DeclarationConst();
			automate.reduction(nbSymboles,s);
			break;
		}
		default : break;
	}
	return false;
}

