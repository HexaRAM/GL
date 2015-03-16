#ifndef PROGRAMME_H 
#define PROGRAMME_H

#include "symbole.h"
#include "blocInstruction.h"
#include "declaration/blocDeclaration.h"

	class Programme : public Symbole {
	protected:
		BlocDeclaration bloc_declaration;
		BlocInstruction bloc_instruction;
	public:
		Programme(): Symbole(0) {}
		virtual ~Programme() {}
		void print();
	};
#endif