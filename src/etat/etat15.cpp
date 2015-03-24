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

			automate.popAndDeleteState();
			automate.popSymbole(); // on ne supprime pas id

			automate.reduction(s);
			break;
		}
		default : break;
	}
	return false;
}

