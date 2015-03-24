#include "etat35.h"
#include "etat41.h"
#include "etat30.h"
#include "etat31.h"
#include "etat29.h"
#include "../config.h"


Etat35::Etat35(string pName) : Etat(pName){}
Etat35::Etat35(){}
Etat35::~Etat35(){}

bool Etat35::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case pf :
			automate.decalage(s, new Etat41("41"));
			break;
		case add :
			automate.decalage(s, new Etat30("30"));
			break;
		case moins :
			automate.decalage(s, new Etat31("31"));
			break;
		case OA :
			automate.decalage(s, new Etat29("29"));
			break;
		default : break;
	}
	return false;
}

Etat* Etat35::next(Symbole* s)
{
	switch (*s)
	{
		case OA:
			return new Etat29("29");
		break;

		default:
			return NULL;
		break;
	}
}
