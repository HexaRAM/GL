#include "etat37.h"
#include "../config.h"
#include "../symbole/declaration/declarationConst.h"


Etat37::Etat37(string pName) : Etat(pName){}
Etat37::Etat37(){}
Etat37::~Etat37(){}

bool Etat37::transition(Automate& automate, Symbole* s ){
	int idSym = *s ; 
	switch (idSym) {
		case v :
		case pv :
		{
			//Regle R7 : C → id eg num
			int nbSymboles = 3;
			Num* newNum = (Num*)automate.getNthSymbole(0);
			Identificateur* newId = (Identificateur*)automate.getNthSymbole(2);
			DeclarationConst* newConst= new DeclarationConst();
			newConst->addConst(newId, newNum);

			// check doublons
			bool ok = Identificateur::checkDouble((string)*newId);
			if (!ok)
			{
				return false;
			}

			for (unsigned int i = 0; i < nbSymboles; ++i)
			{
				automate.popAndDeleteState();
			}

			automate.popSymbole(); // on conserve num
			automate.popAndDeleteSymbole(); // on détruit eg
			automate.popSymbole(); // on conserve id

			automate.reduction(newConst);
			break;
		}
		default :
			// récupération ici -> on suppose que ça sera un point-virgule plutôt qu'une virgule (on n'est pas sûr)
			automate.recuperation(new Symbole(100), true);
		break;
	}
	return false;
}

