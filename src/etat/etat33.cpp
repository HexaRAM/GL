#include "etat33.h"
#include "../config.h"
#include "../symbole/expr/exprMult.h"

Etat33::Etat33(string pName) : Etat(pName){}
Etat33::Etat33(){}
Etat33::~Etat33(){}

bool Etat33::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		//R24
		case id :
		case num :
		case po :
		{
			int nbSymboles = 1;
			Symbole* s= new ExprMult();		
			automate.reduction(nbSymboles,s);
			break;
		}
		default : break;
	}
	return false;
}

