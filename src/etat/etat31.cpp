#include "etat31.h"
#include "../config.h"
#include "../symbole/oa.h"


Etat31::Etat31(string pName) : Etat(pName){}
Etat31::Etat31(){}
Etat31::~Etat31(){}

bool Etat31::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case id :
		case num :
		case po :
		{
			//R23 : OA -> -
			int nbSymboles = 1;
			oa* s = new oa("-");
			automate.reduction(nbSymboles,s);
			break;
		}
			break;
		default : break;
	}
	return false;
}

