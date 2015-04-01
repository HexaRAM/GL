#ifndef PROGRAMME_H 
#define PROGRAMME_H

#include "symbole.h"
#include "affectation.h"
#include "blocInstruction.h"
#include "declaration/blocDeclaration.h"

	class Programme : public Symbole {
		protected:
			BlocDeclaration* bloc_declaration;
			BlocInstruction* bloc_instruction;
		public:
			Programme(): Symbole(0) {}
			Programme(BlocDeclaration* blocDecl, BlocInstruction* blocInstr);
			BlocInstruction* getBlocInstruction();
			virtual ~Programme();
			void print(ostream& os) const;
			BlocDeclaration* getBlocDeclaration() { return bloc_declaration; }

	};
#endif
