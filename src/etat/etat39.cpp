#include "etat39.h"
#include "etat0.h"
#include "etat1.h"
#include "../config.h"


Etat39::Etat39(string pName) : Etat(pName){}
Etat39::Etat39(){}
Etat39::~Etat39(){}

bool Etat39::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case pf :
			//TODO : r15
			break;
		case add :
			//TODO : r15
			break;
		case moins :
			//TODO : r15
		case fois :
			//automate.decalage(s, new Etat33);
		case divise :
			//automate.decalage(s, new Etat34);
		case pv :
			//TODO : r15
		default : break;
	}
	return false;
}

