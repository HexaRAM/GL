#include "etat28.h"
#include "etat20.h"
#include "etat21.h"
#include "etat22.h"
#include "etat23.h"
#include "etat24.h"
#include "../config.h"

Etat28::Etat28(string pName) : Etat(pName){}
Etat28::Etat28(){}
Etat28::~Etat28(){}

bool Etat28::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case id :
			automate.decalage(s, new Etat22);
			break;
		case num :
			automate.decalage(s, new Etat23);
			break;
		case po :
			automate.decalage(s, new Etat24);
			break;
		case E : 
			automate.decalage(s, new Etat28);
			break;
		case T : 
			automate.decalage(s, new Etat20);
			break;
		case F : 
			automate.decalage(s, new Etat21);
			break;
		default : break;
	}
	return false;
}

