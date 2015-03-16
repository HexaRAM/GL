#ifndef IDENTIFICATEUR_H 
#define IDENTIFICATEUR_H

#include "../expr/expression.h"
#include <string>

using namespace std;

	class Identificateur : public Expression {
		protected:
			string nom;
		public:
			Identificateur(): Expression(104) {}
			Identificateur(string str); 
			virtual ~Identificateur() {}
	};
#endif
