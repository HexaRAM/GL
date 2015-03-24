#include "etat39.h"
#include "etat33.h"
#include "etat34.h"
#include "etat32.h"
#include "etat1.h"
#include "../symbole/expr/expression.h"
#include "../symbole/oa.h"
#include "../symbole/expr/exprPlus.h"
#include "../symbole/expr/exprMoins.h"
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
		{
			//R15 : E → E OA T
			int nbSymboles = 3;
			Expression* exprDroite = (Expression*) automate.getNthSymbole(0);
			oa* operateur = (oa*) automate.getNthSymbole(1);
			Expression* exprGauche = (Expression*) automate.getNthSymbole(2);

			string type = operateur->getType();

			Expression* expr = NULL;

			if (type == "+")
			{
				// +
				expr = (ExprPlus*) new ExprPlus(exprGauche, exprDroite);
			}
			else if (type == "-")
			{
				// -
				expr = (ExprMoins*) new ExprMoins(exprGauche, exprDroite);
			}
			else
			{
				// error dans le type
			}

			automate.reduction(nbSymboles,expr);
			break;	
		}	

		case fois :
			automate.decalage(s, new Etat33("33"));
		case divise :
			automate.decalage(s, new Etat34("34"));
		
		case OM :
			automate.decalage(s, new Etat32("32"));
			break;
		default:
		break;
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