#include "programme.h"

Programme::Programme(BlocDeclaration* blocDecl, BlocInstruction* blocInstr) : Symbole(0)
{	
	bloc_declaration = blocDecl;
	bloc_instruction = blocInstr;
}	

Programme::~Programme()
{
    // destruction du programme par bloc (récursif)
    delete bloc_declaration;
    delete bloc_instruction;
}

void Programme::print(ostream& os) const
{
	os << *bloc_declaration << *bloc_instruction;
}

BlocInstruction* Programme::getBlocInstruction()
{
	return bloc_instruction;
}