#ifndef EXPRPLUS_H 
#define EXPRPLUS_H

#include "exprBin.h"

	class ExprPlus : public ExprBin {
		public:
			ExprPlus(): ExprBin() {}
			ExprPlus(Expression* gauche, Expression* droite): ExprBin(gauche, droite) {}
			double eval(const map<string, double> &valeurs);
			Expression* neutralOpti();
			virtual ~ExprPlus() {}
			void print(ostream& os) const;
	};
#endif
