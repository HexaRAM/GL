#include "etat34.h"
#include "../config.h"
#include "../symbole/expr/exprDiv.h"

Etat34::Etat34(string pName) : Etat(pName){}
Etat34::Etat34(){}
Etat34::~Etat34(){}

bool Etat34::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		//R25
		case id :
		case num :
		case po :
		{
			int nbSymboles = 1;
			Symbole* s= new ExprDiv();		
			automate.reduction(nbSymboles,s);
			break;
		}
		default : break;
	}
	return false;
}

