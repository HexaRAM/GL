#include "etat20.h"
#include "etat32.h"
#include "etat33.h"
#include "etat34.h"
//#include "../symbole/expr/terme.h"
#include "../config.h"

Etat20::Etat20(string pName) : Etat(pName){}
Etat20::Etat20(){}
Etat20::~Etat20(){}

bool Etat20::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case fois :
			automate.decalage(s, new Etat33);
			break;
		case divise :
			automate.decalage(s, new Etat34);
			break;
		case pf :
		case add :
		case moins :
		case pv :
		{
			//TODO : r16 E → T
			int nbSymboles = 1;
			Symbole* s /*= new TERME()*/;		
			automate.reduction(nbSymboles,s);
			break;
		}
		case OM : 
			automate.decalage(s, new Etat32);
			break;
		default : break;
	}
	return false;
}

Etat* Etat20::next(Symbole* s)
{
	switch (*s)
	{
		case OM:
			return new Etat32("32");
		break;

		default:
			return NULL;
		break;
	}
}

