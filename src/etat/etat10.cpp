#include "etat10.h"
#include "../config.h"

Etat10::Etat10(string pName) : Etat(pName){}
Etat10::Etat10(){}
Etat10::~Etat10(){}

bool Etat10::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case E :
			//automate.decalage(s, new Etat 19);
			break;
		case T :
			//automate.decalage(s, new Etat 20);
			break;
		case F :
			//automate.decalage(s, new Etat 21);
			break;
		case id :
			//automate.decalage(s, new Etat 22);
			break;
		case num :
			//automate.decalage(s, new Etat 23);
			break;
		case po :
			//automate.decalage(s, new Etat 24);
			break;
		default : break;
	}
	return false;
}

