#include "etat18.h"
#include "../symbole/lecture.h"
#include "../symbole/declaration/identificateur.h"
#include "../config.h"

Etat18::Etat18(string pName) : Etat(pName){}
Etat18::Etat18(){}
Etat18::~Etat18(){}

bool Etat18::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case pv :
		{
			// R13 I → r id
			int nbSymboles = 2;
			Identificateur* identif = (Identificateur*) automate.getNthSymbole(0);
			Symbole* lect = new Lecture(identif);

			for (unsigned int i = 0; i < nbSymboles; ++i)
			{
				automate.popAndDeleteState();
			}

			automate.popSymbole(); // on garde id
			automate.popAndDeleteSymbole();


			automate.reduction(lect);
			break;
		}
		default : break;
	}
	return false;
}