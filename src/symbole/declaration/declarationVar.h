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
		DeclarationVar(): Declaration() {}
		void addIdentificateur(Identificateur* ident);
		void declarationFinie() { ident = 4; }
		virtual ~DeclarationVar() {}
	};
#endif
