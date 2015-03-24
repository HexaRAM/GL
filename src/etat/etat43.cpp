#include "etat43.h"
#include "etat0.h"
#include "etat1.h"
#include "../config.h"
#include "../symbole/declaration/declarationConst.h"


Etat43::Etat43(string pName) : Etat(pName){}
Etat43::Etat43(){}
Etat43::~Etat43(){}

bool Etat43::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case v :
		case pv :
		//Reduction R6 : C → C v id eg num
		{
			int nbSymboles = 5;

			Num* num = (Num*) automate.getNthSymbole(0);
			Identificateur* identif = (Identificateur*) automate.getNthSymbole(2);
			DeclarationConst* declaC = ((DeclarationConst*) automate.getNthSymbole(4));
			declaC->addConst(identif, num);

			// réduction manuelle ici
			for (unsigned int i = 0; i < nbSymboles; ++i) 
			{
				automate.popAndDeleteState();
			}

			for (unsigned int i = 0; i < nbSymboles-1; ++i)
			{
				automate.popAndDeleteSymbole();
			}
			automate.popSymbole(); // on le pop sans le supprimer car il s'agit de declaC

			automate.reduction(declaC); // réduction manuelle
			break;
		}
		default : break;
	}
	return false;
}

