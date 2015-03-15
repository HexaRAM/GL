#ifndef DECLARATIONVAR_H 
#define DECLARATIONVAR_H

#include "declaration.h"
#include "identificateur.h"

#include <deque>

	class DeclarationVar : public Declaration {
	protected:
		//deque<Identificateur> liste_identif;
	public:
		DeclarationVar(): Declaration() {}
		virtual ~DeclarationVar() {}
	};
#endif