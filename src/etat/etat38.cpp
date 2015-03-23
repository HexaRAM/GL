#include "etat38.h"
#include "../config.h"
#include "../symbole/declaration/declarationVar.h"


Etat38::Etat38(string pName) : Etat(pName){}
Etat38::Etat38(){}
Etat38::~Etat38(){}

bool Etat38::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case v :
		case pv :
		{
			//Regle R8 : V → V v id
			int nbSymboles = 3;
			Identificateur* identif = (Identificateur*) automate.getNthSymbole(0);
			DeclarationVar* declaV = ((DeclarationVar*) automate.getNthSymbole(2));
			declaV->addIdentificateur(identif);

			// réduction manuelle ici
			for (unsigned int i = 0; i < nbSymboles; ++i) 
			{
				automate.popAndDeleteState();
			}

			automate.popAndDeleteSymbole();
			automate.popAndDeleteSymbole();
			automate.popSymbole(); // on le pop sans le supprimer car il s'agit de declaV

			automate.reduction(declaV); // réduction manuelle
			break;
		}
		default : break;
	}
	return false;
}

