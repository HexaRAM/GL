#ifndef ECRITURE_H 
#define ECRITURE_H

#include "instruction.h"
#include "expr/expression.h"

#include <iostream>

using namespace std;

	class  Ecriture : public Instruction{
		protected:
			Expression* expr;
		public:
			Ecriture(){}
			Ecriture(Expression* e);
			virtual ~Ecriture();
			void print(ostream& os) const;
			Expression* getExpression();
			void setExpression(Expression * expression);
	};
#endif