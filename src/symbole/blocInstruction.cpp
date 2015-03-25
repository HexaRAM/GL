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

void BlocInstruction::getAffectationConstants(){
	//cout<<liste_instruction.size()<<endl;
	for(auto const &it:liste_instruction){
		Affectation* aff = dynamic_cast<Affectation*> (it);
		if(aff != NULL){
			ExprBin * rht = dynamic_cast<ExprBin*> (aff->getExpression());
			if (rht != NULL){
				rht->getExprGauche()->print(cout);
			}

		} 
	}

}