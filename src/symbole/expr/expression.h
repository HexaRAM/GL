#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "../symbole.h"
#include <map>
#include <set>
#include <string>

class Identificateur; // cross reference

using namespace std;

	class Expression: public Symbole { 
		public:
			Expression():Symbole(7) {}
			Expression(int identifiant) : Symbole(identifiant) {}
			virtual ~Expression() {}
            virtual void setE() { ident = 7; }
            virtual void setF() { ident = 9; }
            virtual void setT() { ident = 8; }
			virtual double eval(const map<string, double> &valeurs);
			virtual void print(ostream& os) const;
            virtual set<Identificateur*>  getIdents() const;
	};
	
#endif
