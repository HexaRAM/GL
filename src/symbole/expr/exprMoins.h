#ifndef EXPRMOINS_H 
#define EXPRMOINS_H

#include "exprBin.h"

	class ExprMoins : public ExprBin {
		public:
			ExprMoins(): ExprBin() {}
			ExprMoins(Expression* gauche, Expression* droite): ExprBin(gauche, droite) {}
			double eval(const map<string, double> &valeurs);
			virtual ~ExprMoins() {}
			void print(ostream& os) const;
	};
#endif
