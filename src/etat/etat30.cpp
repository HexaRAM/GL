#include "etat30.h"
#include "../config.h"
#include "../symbole/oa.h"

Etat30::Etat30(string pName) : Etat(pName){}
Etat30::Etat30(){}
Etat30::~Etat30(){}

bool Etat30::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {

		case id :
		case num :
		case po :
			//R22 : OA -> +
		{
			int nbSymboles = 1;
			oa* s = new oa("+");
			automate.reduction(nbSymboles,s);
			break;
		}
			
		default : break;
	}
	return false;
}

