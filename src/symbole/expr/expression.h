#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "../symbole.h"
#include <map>
#include <string>

using namespace std;

	class Expression: public Symbole { 
		public:
			Expression():Symbole(7) {}
			Expression(int ident):Symbole(ident) {}
			virtual ~Expression() {}
			double eval(const map<string, double> &valeurs);
			//void print(ostream& os) const;
			//friend ostream& operator<<(ostream& os, const Expression& dt) = 0;
	};
	
#endif
