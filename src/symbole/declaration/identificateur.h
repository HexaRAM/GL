#ifndef IDENTIFICATEUR_H 
#define IDENTIFICATEUR_H

#include "../expr/expression.h"
#include <string>
#include <map>
#include <set>

using namespace std;

	class Identificateur : public Expression {
		protected:
			string nom;
			bool linkedToVar;
		public:
			Identificateur(): Expression(104), linkedToVar(false) {}
			Identificateur(string str) : Expression(104), nom(str), linkedToVar(false) {} 
			double eval(const map<string, double> &valeurs);
			virtual ~Identificateur() {}
			void print(ostream& os) const;
			operator string() const { return nom; }
			set<Identificateur*> getIdents() const;
			inline void linkToVar() { linkedToVar = true; }
			inline bool isLinkedToVar() { return linkedToVar; }


	};
#endif
