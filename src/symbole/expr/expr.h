#if !defined ( EXPR_H )
#define EXPR_H

#include "../symbole.h"

class Expr: public Symbole { 
	public:
		Expr():Symbole(EXPR) {}
		virtual ~Expr() {}
		virtual double eval(const map<string, double> &valeurs) = 0;
};
#endif