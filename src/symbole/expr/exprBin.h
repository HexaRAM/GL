#ifndef EXPRBIN_H 
#define EXPRBIN_H

#include "expression.h"

	class ExprBin : public Expression {
		protected:
			Expression * expr_gauche;
			Expression * expr_droite;
		public:
			ExprBin(): Expression() {}
			ExprBin(Expression* gauche, Expression* droite);
			virtual ~ExprBin() {}
	};
#endif
