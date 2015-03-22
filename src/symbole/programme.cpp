#include "programme.h"

Programme::Programme(BlocDeclaration* blocDecl, BlocInstruction* blocInstr) : Symbole(0) {
	
	bloc_declaration = blocDecl;
	bloc_instruction = blocInstr;
}
