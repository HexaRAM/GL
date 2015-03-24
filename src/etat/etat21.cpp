#include "etat21.h"
#include "../config.h"
#include "../symbole/declaration/num.h"

Etat21::Etat21(string pName) : Etat(pName){}
Etat21::Etat21(){}
Etat21::~Etat21(){}

bool Etat21::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case pf :
		case add :
		case moins :
		case fois :
		case divise :
		case pv :
			//Reduction r18 : T-> F
		{
			Expression* expr = (Expression*)automate.getNthSymbole(0);
			expr->setT();

			automate.popAndDeleteState();
			automate.popSymbole();

			automate.reduction(expr);
			break;
		}
			
		default : break;
	}
	return false;
}

