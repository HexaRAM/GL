#include "etat3.h"
#include "etat7.h"
#include "etat8.h"
#include "etat9.h"
#include "etat10.h"
#include "../config.h"
#include "../symbole/programme.h"

Etat3::Etat3(string pName) : Etat(pName){}
Etat3::Etat3(){}
Etat3::~Etat3(){}

bool Etat3::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case I :
			automate.decalage(s, new Etat7("7"));
			break;
		case id :
			automate.decalage(s, new Etat8("8"));
			break;
		case r :
			automate.decalage(s, new Etat9("9"));
			break;
		case w :
			automate.decalage(s, new Etat10("10"));
			break;
		case dollar :
		{
			//réduction r1 : P -> LD LI
			int nbSymboles = 2;
			BlocInstruction* newLi = (BlocInstruction*)automate.getNthSymbole(0);
			BlocDeclaration* newLd = (BlocDeclaration*)automate.getNthSymbole(1);
			Symbole * s = new Programme(newLd, newLi);
			automate.reduction(nbSymboles,s);
			break;
		}
		default : break;
	}
	return false;
}

Etat* Etat3::next(Symbole* s)
{
	switch (*s)
	{
		case I:
			return new Etat7("7");
		break;

		default:
			return NULL;
		break;
	}
}

