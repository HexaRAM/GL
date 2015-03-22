#include "etat12.h"
#include "etat25.h"
#include "../config.h"
#include "../symbole/declaration/declaration.h"

Etat12::Etat12(string pName) : Etat(pName){}
Etat12::Etat12(){}
Etat12::~Etat12(){}

bool Etat12::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case v :
			automate.decalage(s, new Etat25);
			break;
		case pv :
		{
			//Reduction r4 : D -> ct C
			int nbSymboles = 2;
			Symbole* s= new Declaration();
			automate.reduction(nbSymboles,s);
			break;
		}
		default : break;
	}
	return false;
}

