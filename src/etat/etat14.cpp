#include "etat14.h"
#include "etat27.h"
#include "../config.h"
#include "../symbole/declaration/declarationVar.h"

Etat14::Etat14(string pName) : Etat(pName){}
Etat14::Etat14(){}
Etat14::~Etat14(){}

bool Etat14::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case v :
			automate.decalage(s, new Etat27("27"));
			break;
		case pv :
		{
			//Reduction r5 : D -> va V
			int nbSymboles = 2;
			DeclarationVar* declaV = ((DeclarationVar*) automate.getNthSymbole(0));
			declaV->declarationFinie();

			// réduction manuelle ici
			for (unsigned int i = 0; i < nbSymboles; ++i) 
			{
				automate.popAndDeleteState();
			}

			automate.popSymbole(); // on le pop sans le supprimer car il s'agit de declaV
			automate.popAndDeleteSymbole();

			automate.reduction(declaV); // réduction manuelle
			break;
		}
		default : break;
	}
	return false;
}

