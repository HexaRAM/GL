#include "blocInstruction.h"

void BlocInstruction::addInstruction(Instruction* inst){
	liste_instruction.push_front(inst);
}

void BlocInstruction::print(ostream& os) const {
	//TODO
}