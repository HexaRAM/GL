#ifndef EXPRBIN_H 
#define EXPRBIN_H

#include "expression.h"

	class ExprBin : public Expression {
		protected:
			Expression expr_droite;
			Expression expr_gauche;
		public:
			ExprBin(){}
			virtual ~ExprBin() {}
	};
#endif