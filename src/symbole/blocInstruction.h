#ifndef BLOCINSTRUCTION_H 
#define BLOCINSTRUCTION_H

#include "symbole.h"
#include "expr/exprBin.h"
#include "instruction.h"
#include "affectation.h"
#include <vector>

using namespace std;

	class BlocInstruction : public Symbole {
		protected:
			vector<Instruction*> liste_instruction;
		public:
			BlocInstruction(): Symbole(5) {}
			void addInstruction(Instruction* inst);
			vector<Instruction*> getListeInstruction();
			virtual ~BlocInstruction();
			void print(ostream& os) const;
	};
#endif
