#include "etat22.h"
#include "../config.h"
#include "../symbole/declaration/identificateur.h"

Etat22::Etat22(string pName) : Etat(pName){}
Etat22::Etat22(){}
Etat22::~Etat22(){}

bool Etat22::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case pf :
		case add :
		case moins :
		case fois :
		case divise :
		case pv :
			//Reduction r19 : F -> id
		{
			Identificateur* identif= (Identificateur*) automate.getNthSymbole(0);
			identif->setF();

			automate.popAndDeleteState();
			automate.popSymbole();

			automate.reduction(identif);
			break;
		}
			
		default : break;
	}
	return false;
}

