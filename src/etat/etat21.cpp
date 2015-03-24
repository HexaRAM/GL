#include "etat21.h"
#include "../config.h"
#include "../symbole/declaration/num.h"

Etat21::Etat21(string pName) : Etat(pName){}
Etat21::Etat21(){}
Etat21::~Etat21(){}

bool Etat21::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case pf :
		case add :
		case moins :
		case fois :
		case divise :
			//Reduction r18 : T-> F
		{
			int nbSymboles = 1;
			Symbole* s= new Num();		
			automate.reduction(nbSymboles,s);
			break;
		}
			
		default : break;
	}
	return false;
}

