#ifndef DECLARATIONVAR_H 
#define DECLARATIONVAR_H

#include "declaration.h"
#include "identificateur.h"

#include <deque>
using namespace std;

	class DeclarationVar : public Declaration {
	protected:
		deque<Identificateur*> liste_identif;
	public:
		DeclarationVar(): Declaration(4) {}
		void addIdentificateur(Identificateur* ident);
		void declarationFinie() { ident = 2; }
		virtual ~DeclarationVar() {}
		void print(ostream& os) const;
	};
#endif
