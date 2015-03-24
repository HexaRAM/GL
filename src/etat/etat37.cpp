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
			Num* newNum = (Num*)automate.getNthSymbole(0);
			Identificateur* newId = (Identificateur*)automate.getNthSymbole(2);
			DeclarationConst* newConst= new DeclarationConst();
			newConst->addConst(newId, newNum);
			automate.reduction(nbSymboles, newConst);
			break;
		}
		default : break;
	}
	return false;
}

