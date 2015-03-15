#ifndef AFFECTATION_H 
#define AFFECTATION_H

#include "instruction.h"
#include "expr/expression.h"
#include "expr/variable.h"

	class  Affectation : public Instruction{
		protected:
			Expression expr;
			Variable var;
		public:
			Affectation():Instruction(107) {}
			virtual ~Affectation() {}
			void print();
	};
#endif