#ifndef BLOCINSTRUCTION_H 
#define BLOCINSTRUCTION_H

#include "symbole.h"
#include "expr/exprBin.h"
#include "instruction.h"
#include "affectation.h"
#include <deque>

using namespace std;

	class BlocInstruction : public Symbole {
		protected:
			deque<Instruction*> liste_instruction;
		public:
			BlocInstruction(): Symbole(5) {}
			void addInstruction(Instruction* inst);
			deque<Instruction*> getListeInstruction();
			virtual ~BlocInstruction() {}
			void print(ostream& os) const;
			void getAffectationConstants();
	};
#endif
