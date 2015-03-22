#include "etat14.h"
#include "etat27.h"
#include "../config.h"
#include "../symbole/declaration/declaration.h"

Etat14::Etat14(string pName) : Etat(pName){}
Etat14::Etat14(){}
Etat14::~Etat14(){}

bool Etat14::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case v :
			automate.decalage(s, new Etat27);
			break;
		case pv :
		{
			//Reduction r5 : D -> va V
			int nbSymboles = 2;
			Symbole* s= new Declaration();
			automate.reduction(nbSymboles,s);
			break;
		}
		default : break;
	}
	return false;
}

