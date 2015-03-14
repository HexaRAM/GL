#include "etat41.h"
#include "etat0.h"
#include "etat1.h"
#include "../config.h"


Etat41::Etat41(string pName) : Etat(pName){}
Etat41::Etat41(){}
Etat41::~Etat41(){}

bool Etat41::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case pf :
			//TODO : r21
			break;
		case add :
			//TODO : r21
			break;
		case moins :
			//TODO : r21
		case fois :
			//TODO : r21
		case divise :
			//TODO : r21
		default : break;
	}
	return false;
}

