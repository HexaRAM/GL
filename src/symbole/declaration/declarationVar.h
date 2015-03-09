#ifndef DECLARATIONVAR_H 
#define DECLARATIONVAR_H

#include "declaration.h"
#include "Identificateur.h"

	class DeclarationVar : public Declaration {
	protected:
		deque<Identificateur> liste_identif;
	public:
		DeclarationVar() {}
		virtual ~DeclarationVar() {}
	};
#endif