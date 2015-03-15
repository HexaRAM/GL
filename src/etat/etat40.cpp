#include "etat40.h"
#include "etat0.h"
#include "etat1.h"
#include "etat43.h"
#include "../config.h"


Etat40::Etat40(string pName) : Etat(pName){}
Etat40::Etat40(){}
Etat40::~Etat40(){}

bool Etat40::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case pf :
			//TODO : r17
			break;
		case add :
			//TODO : r17
			break;
		case moins :
			//TODO : r17
		case fois :
			//TODO : r17
		case divise :
			//TODO : r17
		default : break;
	}
	return false;
}

