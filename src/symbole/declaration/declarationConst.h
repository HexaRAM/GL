#ifndef DECLARATIONCONST_H 
#define DECLARATIONCONST_H

#include "declaration.h"
#include "num.h"
#include "identificateur.h"
#include <vector>

	struct constante
	{
		Identificateur* ident;
		Num* value;
	};

	class DeclarationConst : public Declaration {
	protected:
		vector<constante> constantes;
	public:
		DeclarationConst(): Declaration(3) {}
		void addConst(Identificateur* ident, Num* num);
        void declarationFinie() { ident = 2; }
		virtual ~DeclarationConst() {}
		void print(ostream& os) const;
		vector<constante> getConstantes() { return constantes; }
	};
#endif