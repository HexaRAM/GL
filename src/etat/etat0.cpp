#include "etat0.h"
#include "etat1.h"
#include "etat2.h"
#include "../config.h"


Etat0::Etat0(string pName) : Etat(pName){}
Etat0::~Etat0(){}

bool Etat0::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case P :
			automate.decalage(s, new Etat1);
			break;
		case LD :
			automate.decalage(s, new Etat2);
			break;
		case ct :
		case va :
		case dollar :
			/** TODO **/
			//automate.reduction();
			break;
		default : break;
	}
	return false;
}

