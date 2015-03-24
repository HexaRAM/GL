#include "../config.h"
#include "../symbole/declaration/blocDeclaration.h"
#include "etat16.h"

Etat16::Etat16(string pName) : Etat(pName){}
Etat16::Etat16(){}
Etat16::~Etat16(){}

bool Etat16::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case id :
		case r :
		case w : 
		case dollar :
		{
			// TODO r10 LI → LI I pv
			int nbSymboles = 3;
			Symbole* s= new BlocDeclaration();		
			automate.reduction(nbSymboles,s);
			break;
		}
		default : break;
	}
	return false;
}

