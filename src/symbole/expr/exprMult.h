#ifndef EXPRMULT_H 
#define EXPRMULT_H

#include "exprBin.h"


	class ExprMult : public ExprBin {
		public:
			ExprMult(): ExprBin() {}
			ExprMult(Expression* gauche, Expression* droite): ExprBin(gauche, droite) { ident = 8; }
			double eval(const map<string, double> &valeurs);
			Expression * neutralOpti();
			virtual ~ExprMult() {}
			friend ostream& operator<<(ostream& os, const ExprMult& dt);
			void print(ostream& os) const;
	};
#endif
