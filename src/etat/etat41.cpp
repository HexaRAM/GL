#include "etat41.h"
#include "etat0.h"
#include "etat1.h"

#include "../symbole/expr/expression.h"
#include "../symbole/expr/opParenthese.h"
#include "../config.h"


Etat41::Etat41(string pName) : Etat(pName){}
Etat41::Etat41(){}
Etat41::~Etat41(){}

bool Etat41::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		// R21 : F -> (E)
		case pf :
		case add :
		case moins :
		case fois :
		case divise :
		case pv :
		{
			int nbSymboles = 3;
			Expression* expr = (Expression*) automate.getNthSymbole(1);
			OpParenthese* opPar = new OpParenthese(expr);
			automate.reduction(nbSymboles, opPar);
		}
		break;
		default:

		break;
	}
	return false;
}

