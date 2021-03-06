#include "etat32.h"
#include "etat40.h"
#include "etat22.h"
#include "etat23.h"
#include "etat24.h"
#include "../config.h"


Etat32::Etat32(string pName) : Etat(pName){}
Etat32::Etat32(){}
Etat32::~Etat32(){}

bool Etat32::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case id :
			automate.decalage(s, new Etat22("22"));
			break;
		case num :
			automate.decalage(s, new Etat23("23"));
			break;
		case po :
			automate.decalage(s, new Etat24("24"));
			break;
		case F :
			automate.decalage(s, new Etat40("40"));
			break;
		default : break;
	}
	return false;
}

Etat* Etat32::next(Symbole* s)
{
	switch (*s)
	{
		case F:
			return new Etat40("40");
		break;

		default:
			return NULL;
		break;
	}
}

