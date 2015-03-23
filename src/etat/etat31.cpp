#include "etat31.h"
#include "../config.h"
#include "../symbole/expr/exprMoins.h"


Etat31::Etat31(string pName) : Etat(pName){}
Etat31::Etat31(){}
Etat31::~Etat31(){}

bool Etat31::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case id :
		case num :
		case po :
		{
			//R23
			int nbSymboles = 1;
			Symbole* s= new ExprMoins();		
			automate.reduction(nbSymboles,s);
			break;
		}
			break;
		default : break;
	}
	return false;
}

