#include "../config.h"
#include "../symbole/declaration/blocDeclaration.h"
#include "etat16.h"

Etat16::Etat16(string pName) : Etat(pName){}
Etat16::Etat16(){}
Etat16::~Etat16(){}

bool Etat16::transition(Automate & automate, Symbole * s ){
	int idSym = *s ; 
	switch (idSym) {
		case id :
		case r :
		case w : 
		case dollar :
		{
			// TODO r10 LI → LI I pv
			int nbSymboles = 3;
			Instruction* inst = (Instruction*) automate.getNthSymbole(1);
			BlocInstruction* blocInst = (BlocInstruction*) automate.getNthSymbole(2);
			blocInst->addInstruction(inst);

			// réduction manuelle ici
			for (unsigned int i = 0; i < nbSymboles; ++i) 
			{
				automate.popAndDeleteState();
			}

			automate.popAndDeleteSymbole();
			automate.popSymbole(); // on garde I
			automate.popSymbole(); // on le pop sans le supprimer car il s'agit de blocDec

			automate.reduction(blocInst); // réduction manuelle


			break;
		}
		default : break;
	}
	return false;
}

