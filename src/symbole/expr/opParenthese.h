#ifndef OPPARENTHESE_H 
#define OPPARENTHESE_H

#include "expression.h"

	class OpParenthese : public Expression {
		protected:
			Expression* expr;
		public:
			OpParenthese(): Expression() {}
			OpParenthese(Expression* expression);
			double eval(const map<string, double> &valeurs);
			virtual ~OpParenthese() {}
	};
#endif
