#ifndef IDENTIFICATEUR_H 
#define IDENTIFICATEUR_H

#include "../expr/expression.h"
#include <string>
#include <map>
#include <set>

using namespace std;

	class Identificateur : public Expression 
	{
		protected:
			string nom;
			static set<string> idents;
		public:
			Identificateur(): Expression(104) {}
			Identificateur(string str) : Expression(104), nom(str) {} 
			double eval(const map<string, double> &valeurs);
			Expression* neutralOpti();
			virtual ~Identificateur() {}
			void print(ostream& os) const;
			operator string() const { return nom; }
			set<Identificateur*> getIdents() const;
			static bool checkDouble(const string& name);


	};
#endif
