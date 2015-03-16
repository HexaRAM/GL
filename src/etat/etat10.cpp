#include "etat10.h"
#include "etat19.h"
#include "etat20.h"
#include "etat21.h"
#include "etat22.h"
#include "etat23.h"
#include "etat24.h"
#include "../config.h"

Etat10::Etat10(string pName) : Etat(pName){}
Etat10::Etat10(){}
Etat10::~Etat10(){}

bool Etat10::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case E :
			automate.decalage(s, new Etat19);
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
		case po :
			automate.decalage(s, new Etat24);
			break;
		default : break;
	}
	return false;
}

