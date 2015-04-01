#ifndef AFFECTATION_H 
#define AFFECTATION_H

#include "instruction.h"
#include "expr/expression.h"
#include "declaration/identificateur.h"

	class  Affectation : public Instruction{
		protected:
			Expression* expr;
			Identificateur* id;
		public:
			Affectation():Instruction(107) {}
			Affectation(Expression* expression,	Identificateur* ident);
			virtual ~Affectation();
			void print(ostream& os) const;
			Expression* getExpression();
			Identificateur* getIdentificateur();
			void setExpression(Expression* expression);
	};
#endif
