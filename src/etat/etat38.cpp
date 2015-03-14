#include "etat38.h"
#include "etat0.h"
#include "etat1.h"
#include "../config.h"


Etat38::Etat38(string pName) : Etat(pName){}
Etat38::Etat38(){}
Etat38::~Etat38(){}

bool Etat38::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case v :
			//TODO: r8
			break;
		case pv :
			//TODO: r8
			break;
		default : break;
	}
	return false;
}

