#ifndef OPPARENTHESE_H 
#define OPPARENTHESE_H

#include "expression.h"

	class OpParenthese : public Expression {
		protected:
			Expression* expr;
		public:
			OpParenthese(): Expression() {}
			OpParenthese(Expression* expression);
			virtual ~OpParenthese() {}
	};
#endif
