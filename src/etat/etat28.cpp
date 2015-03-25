#include "etat28.h"
#include "etat30.h"
#include "etat31.h"
#include "etat29.h"
#include "../symbole/declaration/identificateur.h"
#include "../symbole/expr/expression.h"
#include "../symbole/affectation.h"
#include "../config.h"

Etat28::Etat28(string pName) : Etat(pName){}
Etat28::Etat28(){}
Etat28::~Etat28(){}

bool Etat28::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case add :
			automate.decalage(s, new Etat30("30"));
			break;
		case moins :
			automate.decalage(s, new Etat31("31"));
			break;
		case pv :
		{
			//TODO : r12 I → id af E
			int nbSymboles = 3;
			Expression* expr = (Expression*) automate.getNthSymbole(0);
			Identificateur* identif = (Identificateur*) automate.getNthSymbole(2);
			Affectation* aff = new Affectation(expr, identif);		
			for (unsigned int i = 0; i < nbSymboles; ++i)
			{
				automate.popAndDeleteState();
			}

			automate.popSymbole(); // E
			automate.popAndDeleteSymbole();
			automate.popSymbole(); // id

			automate.reduction(aff); // manuelle
			break;
		}
		case OA : 
			automate.decalage(s, new Etat29("29"));
			break;
		default : break;
	}
	return false;
}

Etat* Etat28::next(Symbole* s)
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

