#include "etat18.h"
#include "../symbole/instruction.h"
#include "../config.h"

Etat18::Etat18(string pName) : Etat(pName){}
Etat18::Etat18(){}
Etat18::~Etat18(){}

bool Etat18::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case pv :
		{
			//TODO : r13 I → r id
			int nbSymboles = 2;
			Symbole* s= new Instruction();		
			automate.reduction(nbSymboles,s);
			break;
		}
		default : break;
	}
	return false;
}

