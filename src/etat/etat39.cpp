#include "etat39.h"
#include "etat33.h"
#include "etat34.h"
#include "etat32.h"
#include "etat1.h"
#include "../symbole/expr/expression.h"
#include "../config.h"


Etat39::Etat39(string pName) : Etat(pName){}
Etat39::Etat39(){}
Etat39::~Etat39(){}

bool Etat39::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case pf :
		case add :
		case moins :
		case pv :
		{//TODO : r15 E → E OA T
			int nbSymboles = 3;
			Symbole* s= new Expression();		
			automate.reduction(nbSymboles,s);

			break;	
		}	

		case fois :
			automate.decalage(s, new Etat33);
		case divise :
			automate.decalage(s, new Etat34);
		
		case OM :
			automate.decalage(s, new Etat32);
			break;
		default : break;
	}
	return false;
}

Etat* Etat39::next(Symbole* s)
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