#include "etat20.h"
#include "etat32.h"
#include "etat33.h"
#include "etat34.h"
#include "../symbole/expr/expression.h"
#include "../config.h"

Etat20::Etat20(string pName) : Etat(pName){}
Etat20::Etat20(){}
Etat20::~Etat20(){}

bool Etat20::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case fois :
			automate.decalage(s, new Etat33("33"));
		break;
		case divise :
			automate.decalage(s, new Etat34("34"));
		break;
		case pf :
		case add :
		case moins :
		case pv :
		{
			//TODO : r16 E → T
			Expression* expr = (Expression*)automate.getNthSymbole(0);
			expr->setE();

			automate.popAndDeleteState();
			automate.popSymbole();

			automate.reduction(expr);
			break;
		}
		case OM : 
			automate.decalage(s, new Etat32("32"));
		break;
		default:
		break;
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

