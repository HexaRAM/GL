#include "etat23.h"
#include "../config.h"
#include "../symbole/declaration/num.h"

Etat23::Etat23(string pName) : Etat(pName){}
Etat23::Etat23(){}
Etat23::~Etat23(){}

bool Etat23::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case pf :
		case add :
		case moins :
		case fois :
		case divise :
		case pv :
			//Reduction r20 : F -> num
		{
			Num* num= (Num*) automate.getNthSymbole(0);
			num->setF();

			automate.popAndDeleteState();
			automate.popSymbole();

			automate.reduction(num);
			break;
		}
			
		default : break;
	}
	return false;
}

