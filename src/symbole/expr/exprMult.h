#ifndef EXPRMULT_H 
#define EXPRMULT_H

#include "exprBin.h"

	class ExprMult : public ExprBin {
		public:
			ExprMult(): ExprBin() {}
			ExprMult(Expression* gauche, Expression* droite): ExprBin(gauche, droite) {}
			virtual ~ExprMult() {}
	};
#endif