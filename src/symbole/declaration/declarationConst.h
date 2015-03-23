#ifndef DECLARATIONCONST_H 
#define DECLARATIONCONST_H

#include "declaration.h"
#include "num.h"
#include "identificateur.h"

	class DeclarationConst : public Declaration {
	protected:
		map<Identificateur*,Num*> map_const;
	public:
		DeclarationConst(): Declaration(3) {}
		void addConst(Identificateur* ident, Num* num);
        void declarationFinie() { ident = 2; }
		virtual ~DeclarationConst() {}
	};
#endif
