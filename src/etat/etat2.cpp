#include "etat0.h"
#include "etat1.h"
#include "../config.h"


Etat2::Etat2(string pName) : Etat(pName){}
Etat2::~Etat2(){}

bool Etat2::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case LI :
			automate.decalage(s, new Etat3);
			break;
		case D :
			automate.decalage(s, new Etat4);
			break;
		case ct :
			automate.decalage(s, new Etat5);
		case va :
		case dollar :
			/** TODO **/
			//automate.reduction();
			break;
		default : break;
	}
	return false;
}

