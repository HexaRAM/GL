#ifndef EXPRDIV_H 
#define EXPRDIV_H

#include "exprBin.h"

	class ExprDiv : public ExprBin {
		public:
			ExprDiv(): ExprBin() {}
			ExprDiv(Expression* gauche, Expression* droite): ExprBin(gauche, droite) {}
			double eval(const map<string, double> &valeurs);
			virtual ~ExprDiv() {}
	};
#endif
