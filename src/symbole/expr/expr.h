#if !defined ( EXPR_H )
#define EXPR_H

#include "../symbole.h"
#include <map>
#include <string>

using namespace std;
	class Expr: public Symbole { 
		public:
			Expr():Symbole(0) {}
			virtual ~Expr() {}
			virtual double eval(const map<string, double> &valeurs) = 0;
	};
	
#endif