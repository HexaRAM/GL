#include "etat0.h"
#include "etat1.h"
#include "etat2.h"
#include "../symbole/declaration/blocDeclaration.h"
#include "../config.h"



Etat0::Etat0(string pName) : Etat(pName){}
Etat0::Etat0() : Etat(){}
Etat0::~Etat0(){}

/*
*création du nouveau symbole lors d'une réduction: E->E1+E2
*on a lu sur la pile E1 et E2 , on fait un op plis de E1 et E2 et on obtient le nouveau symbole.
* 
*/


bool Etat0::transition(Automate & automate, Symbole * s )
{
	int idSym = *s ; 

	switch (idSym) 
	{
		case P :
			automate.decalage(s, new Etat1("1"));
			break;
		case LD :
			automate.decalage(s, new Etat2("2"));
			break;
		case ct :
		case r:
		case w:
		case id:
		case va :
		case dollar :
		{
			//R3
			int nbSymboles = 0;
			Symbole* s= new BlocDeclaration();
			automate.reduction(nbSymboles,s);
		}
			break;

		default : break;
	}
	return false;
}

Etat* Etat0::next(Symbole* s)
{
	switch (*s)
	{
		case P:
			return new Etat1("1");
		break;

		case LD:
			return new Etat2("2");
		break;

		default:
			return NULL;
		break;
	}
}
