#include "etat40.h"
#include "etat0.h"
#include "etat1.h"
#include "etat43.h"
#include "../symbole/expr/expression.h"
#include "../symbole/om.h"
#include "../symbole/expr/exprMult.h"
#include "../symbole/expr/exprDiv.h"
#include "../config.h"

Etat40::Etat40(string pName) : Etat(pName){}
Etat40::Etat40(){}
Etat40::~Etat40(){}

bool Etat40::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		// R17 : T -> T OM F
		case pf :
		case add :
		case moins :
		case fois :
		case divise :
		case pv :
		{
			int nbSymboles = 3;
			Expression* exprDroite = (Expression*) automate.getNthSymbole(0);
			om* operateur = (om*) automate.getNthSymbole(1);
			Expression* exprGauche = (Expression*) automate.getNthSymbole(2);

			string type = operateur->getType();

			Expression* expr = NULL;

			if (type == "*")
			{
				// +
				expr = (ExprMult*) new ExprMult(exprGauche, exprDroite);
			}
			else if (type == "/")
			{
				// -
				expr = (ExprDiv*) new ExprDiv(exprGauche, exprDroite);
			}
			else
			{
				// error dans le type
			}
			automate.reduction(nbSymboles,expr);
		}
		break;
		default:

		break;
	}
	return false;
}

