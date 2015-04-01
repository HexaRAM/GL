#include "blocInstruction.h"

BlocInstruction::~BlocInstruction()
{
	// destruction des instructions
	for (auto const &it : liste_instruction)
	{
		delete it;
	}
}

void BlocInstruction::addInstruction(Instruction* inst)
{
	liste_instruction.push_back(inst);
}



void BlocInstruction::print(ostream& os) const
{
	for (auto const &it : liste_instruction)
	{
		os << *it << endl;
	}
}

vector<Instruction*> BlocInstruction::getListeInstruction()
{
	return liste_instruction;
}