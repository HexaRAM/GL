#include "etat15.h"
#include "../symbole/declaration/declarationVar.h"
#include "../symbole/declaration/identificateur.h"
#include "../config.h"

Etat15::Etat15(string pName) : Etat(pName){}
Etat15::Etat15(){}
Etat15::~Etat15(){}

bool Etat15::transition(Automate & automate, Symbole * s ){
	int idSym = *s ;

	switch (idSym) {
		case v :
		case pv :
		{	//Reduction r9 : V -> id
			int nbSymboles = 1;
			DeclarationVar* s = new DeclarationVar(); // V
			Identificateur* identif = (Identificateur*) automate.getNthSymbole(0);
			s->addIdentificateur(identif);

			// check doublons
			bool ok = Identificateur::checkDouble((string)*identif);
			if (!ok)
			{
				return false;
			}

			automate.popAndDeleteState();
			automate.popSymbole(); // on ne supprime pas id

			automate.reduction(s);
			break;
		}
		default : 
			// récupération ici -> on suppose que ça sera une virgule plutôt qu'un point virgule
			automate.recuperation(new Symbole(103), false); // false pour dire "not sure virgule is expected"
		break;
	}
	return false;
}

