#ifndef INSTRUCTION_H 
#define INSTRUCTION_H

#include "symbole.h"

	class Instruction : public Symbole {
	
	public:
		Instruction(): Symbole(6) {}
		Instruction(int id): Symbole(id) {}
		virtual ~Instruction() {}
		void print(ostream& os) const;
	};
#endif
