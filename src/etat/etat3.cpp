#include "etat3.h"
#include "etat7.h"
#include "etat8.h"
#include "etat9.h"
#include "etat10.h"
#include "../config.h"

Etat3::Etat3(string pName) : Etat(pName){}
Etat3::Etat3(){}
Etat3::~Etat3(){}

bool Etat3::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case I :
			automate.decalage(s, new Etat7);
			break;
		case id :
			automate.decalage(s, new Etat8);
			break;
		case r :
			automate.decalage(s, new Etat9);
			break;
		case w :
			automate.decalage(s, new Etat10);
			break;
		case dollar :
			//réduction r1 : P -> LD LI
			break;
		default : break;
	}
	return false;
}

