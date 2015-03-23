#include "etat38.h"
#include "../config.h"
#include "../symbole/declaration/declarationVar.h"


Etat38::Etat38(string pName) : Etat(pName){}
Etat38::Etat38(){}
Etat38::~Etat38(){}

bool Etat38::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case v :
		case pv :
		{
			//Regle R8 : V → V v id
			int nbSymboles = 3;
			Symbole* s= new DeclarationVar();
			automate.reduction(nbSymboles,s);
			break;
		}
		default : break;
	}
	return false;
}

