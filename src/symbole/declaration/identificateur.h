#ifndef IDENTIFICATEUR_H 
#define IDENTIFICATEUR_H

#include "../expr/expression.h"
#include <string>
#include <map>

using namespace std;

	class Identificateur : public Expression {
		protected:
			string nom;
		public:
			Identificateur(): Expression(104) {}
			Identificateur(string str) : Expression(104), nom(str) {} 
			double eval(const map<string, double> &valeurs);
			virtual ~Identificateur() {}
			//friend ostream& operator<<(ostream& os, const Identificateur& dt);
	};
#endif
