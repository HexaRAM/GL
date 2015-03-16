#include "etat24.h"
#include "etat21.h"
#include "etat22.h"
#include "etat20.h"
#include "etat35.h"
#include "etat23.h"
#include "../config.h"

Etat24::Etat24(string pName) : Etat(pName){}
Etat24::Etat24(){}
Etat24::~Etat24(){}

bool Etat24::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case E :
			automate.decalage(s, new Etat35);
			break;
		case T :
			automate.decalage(s, new Etat20);
			break;
		case F :
			automate.decalage(s, new Etat21);
			break;
		case id :
			automate.decalage(s, new Etat22);
			break;
		case num :
			automate.decalage(s, new Etat23);
			break;
		case po:
			automate.decalage(s, new Etat24);
			break;
		default : break;
	}
	return false;
}

