#include "etat12.h"
#include "etat25.h"
#include "../config.h"
#include "../symbole/declaration/declaration.h"
#include "../symbole/declaration/declarationConst.h"

Etat12::Etat12(string pName) : Etat(pName){}
Etat12::Etat12(){}
Etat12::~Etat12(){}

bool Etat12::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case v :
			automate.decalage(s, new Etat25("25"));
			break;
		case pv :
		{
			//Reduction r4 : D -> ct C
			int nbSymboles = 2;
			DeclarationConst* newDec= (DeclarationConst*)automate.getNthSymbole(0);
			newDec->declarationFinie();

			// réduction manuelle ici
			for (unsigned int i = 0; i < nbSymboles; ++i) 
			{
				automate.popAndDeleteState();
			}

			automate.popSymbole(); // on le pop sans le supprimer car il s'agit de newDec
			automate.popAndDeleteSymbole();

			automate.reduction(newDec); // réduction manuelle

			break;
		}
		default : break;
	}
	return false;
}

