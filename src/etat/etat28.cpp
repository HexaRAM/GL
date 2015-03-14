#include "etat28.h"
#include "etat30.h"
#include "etat31.h"
#include "etat29.h"
#include "../config.h"

Etat28::Etat28(string pName) : Etat(pName){}
Etat28::Etat28(){}
Etat28::~Etat28(){}

bool Etat28::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case add :
			automate.decalage(s, new Etat30);
			break;
		case moins :
			automate.decalage(s, new Etat31);
			break;
		case pv :
			//TODO : r12
			break;
		case OA : 
			automate.decalage(s, new Etat29);
			break;
		default : break;
	}
	return false;
}

