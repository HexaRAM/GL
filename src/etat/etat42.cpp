#include "etat42.h"
#include "etat0.h"
#include "etat1.h"
#include "etat43.h"
#include "../config.h"


Etat42::Etat42(string pName) : Etat(pName){}
Etat42::Etat42(){}
Etat42::~Etat42(){}

bool Etat42::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case num :
			automate.decalage(s, new Etat43);
			break;
		default : break;
	}
	return false;
}

