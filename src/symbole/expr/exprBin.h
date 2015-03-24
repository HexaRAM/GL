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
			virtual double eval(const map<string, double> &valeurs)=0;
			virtual ~ExprBin() {}
			virtual void print(ostream& os) const;
	};
#endif
