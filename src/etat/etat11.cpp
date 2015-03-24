#include "etat11.h"
#include "../config.h"
#include "../symbole/declaration/blocDeclaration.h"
#include "../symbole/declaration/declaration.h"

Etat11::Etat11(string pName) : Etat(pName){}
Etat11::Etat11(){}
Etat11::~Etat11(){}

bool Etat11::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case ct :
		case va :
		case r:
		case w:
		case id:
		case dollar :
		{
			//Reduction r2 : LD -> LD D pv
			int nbSymboles = 3;
			Declaration* dec = (Declaration*) automate.getNthSymbole(1);
			BlocDeclaration* blocDec = (BlocDeclaration*) automate.getNthSymbole(2);
			blocDec->addDeclaration(dec);

			// réduction manuelle ici
			for (unsigned int i = 0; i < nbSymboles; ++i) 
			{
				automate.popAndDeleteState();
			}

			automate.popAndDeleteSymbole();
			automate.popSymbole(); // on garde D (dans blocDec)
			automate.popSymbole(); // on le pop sans le supprimer car il s'agit de blocDec

			automate.reduction(blocDec); // réduction manuelle
			break;
		}
		default : break;
	}
	return false;
}

