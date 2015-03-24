#include "etat33.h"
#include "../config.h"
#include "../symbole/om.h"

Etat33::Etat33(string pName) : Etat(pName){}
Etat33::Etat33(){}
Etat33::~Etat33(){}

bool Etat33::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		//R24 : OM -> *
		case id :
		case num :
		case po :
		{
			int nbSymboles = 1;
			om* s = new om("*");
			automate.reduction(nbSymboles,s);
			break;
		}
		default : break;
	}
	return false;
}

