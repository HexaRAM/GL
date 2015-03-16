#ifndef ECRITURE_H 
#define ECRITURE_H

#include "instruction.h"
#include "expr/expression.h"

	class  Ecriture : public Instruction{
		protected:
			Expression expr;
		public:
			Ecriture(){}
			virtual ~Ecriture() {}
			void print();
	};
#endif