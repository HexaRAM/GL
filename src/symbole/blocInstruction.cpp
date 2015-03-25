#include "blocInstruction.h"

void BlocInstruction::addInstruction(Instruction* inst){
	liste_instruction.push_front(inst);
}

void BlocInstruction::print(ostream& os) const {
	for(auto const &it:liste_instruction){
		os << *it;
	}
}
deque<Instruction*> BlocInstruction::getListeInstruction() {
	return liste_instruction;
}