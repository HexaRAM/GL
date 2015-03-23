#ifndef ECRITURE_H 
#define ECRITURE_H

#include "instruction.h"
#include "expr/expression.h"

#include <iostream>

using namespace std;

	class  Ecriture : public Instruction{
		protected:
			Expression expr;
		public:
			Ecriture(){}
			Ecriture(Expression e);
			virtual ~Ecriture() {}
			friend ostream& operator<<(ostream& os, const Ecriture& dt);
			void print(ostream& os) const;
	};
#endif