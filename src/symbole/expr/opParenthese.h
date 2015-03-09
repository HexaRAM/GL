#ifndef OPPARENTHESE_H 
#define OPPARENTHESE_H

#include "expression.h"

	class OpParenthese : public Expression {
		protected:
			Expression expr;
		public:
			OpParenthese(){}
			virtual ~OpParenthese() {}
	};
#endif