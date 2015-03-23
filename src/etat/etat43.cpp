#include "etat43.h"
#include "etat0.h"
#include "etat1.h"
#include "../config.h"
#include "../symbole/declaration/declarationConst.h"


Etat43::Etat43(string pName) : Etat(pName){}
Etat43::Etat43(){}
Etat43::~Etat43(){}

bool Etat43::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case v :
		case pv :
		//Reduction R6 : C → C v id eg num
		{
			int nbSymboles = 5;
			Symbole* s= new DeclarationConst();
			automate.reduction(nbSymboles,s);
			break;
		}
		default : break;
	}
	return false;
}

