#include "etat29.h"
//#include "etat22.h"
//#include "etat23.h"
//#include "etat24.h"
#include "etat39.h"
//#include "etat21.h"
#include "../config.h"


Etat29::Etat29(string pName) : Etat(pName){}
Etat29::Etat29(){}
Etat29::~Etat29(){}

bool Etat29::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case id :
			//automate.decalage(s, new Etat22);
			break;
		case num :
			//automate.decalage(s, new Etat23):
			break;
		case po :
			//automate.decalage(s, new Etat24);
			break;
		case T : 
			automate.decalage(s, new Etat39);
			break;
		case F :
			//automate.decalage(s, new Etat21);
		default : break;
	}
	return false;
}

