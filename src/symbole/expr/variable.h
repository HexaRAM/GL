#ifndef VARIABLE_H 
#define VARIABLE_H

#include "expression.h"

	class Variable : public Expression {
		public:
			Variable(){}
			virtual ~Variable() {}
			void print();
	};
#endif