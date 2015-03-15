#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "../symbole.h"
#include <map>
#include <string>

using namespace std;

	class Expression: public Symbole { 
		public:
			Expression():Symbole(7) {}
			virtual ~Expression() {}
			double eval(const map<string, double> &valeurs);
	};
	
#endif