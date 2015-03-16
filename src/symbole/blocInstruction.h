#ifndef BLOCINSTRUCTION_H 
#define BLOCINSTRUCTION_H

#include "symbole.h"
#include "instruction.h"

#include <deque>

using namespace std;

	class BlocInstruction : public Symbole {
		protected:
			deque<Instruction> liste_instruction;
		public:
			BlocInstruction(): Symbole(5) {}
			virtual ~BlocInstruction() {}
			void print();
	};
#endif