#ifndef EXPRDIV_H 
#define EXPRDIV_H

#include "exprBin.h"

	class ExprDiv : public ExprBin {
		public:
			ExprDiv(): ExprBin() {}
			ExprDiv(Expression* gauche, Expression* droite): ExprBin(gauche, droite) { ident = 8; }
			double eval(const map<string, double> &valeurs);
			Expression* neutralOpti();
			virtual ~ExprDiv() {}
			void print(ostream& os) const;
	};
#endif
