#include "programme.h"

Programme::Programme(BlocDeclaration* blocDecl, BlocInstruction* blocInstr) : Symbole(0) {
	
	bloc_declaration = blocDecl;
	bloc_instruction = blocInstr;
}

void Programme::getAffectationsConstants(){
	//cout<<"hello"<<endl;
	bloc_instruction->getAffectationConstants();
}
	

void Programme::print(ostream& os) const {
	os << *bloc_declaration << *bloc_instruction;
}