#include "blocInstruction.h"

void BlocInstruction::addInstruction(Instruction* inst){
	liste_instruction.push_front(inst);
}



void BlocInstruction::print(ostream& os) const {
	for(auto const &it:liste_instruction){
		os << *it;
	}
}

void BlocInstruction::getAffectationConstants(){
	//cout<<liste_instruction.size()<<endl;
	for(auto const &it:liste_instruction){
		Affectation* aff = dynamic_cast<Affectation*> (it);
		if(aff != NULL){
			aff->getExpression()->print(cout);
		} 
	}

}