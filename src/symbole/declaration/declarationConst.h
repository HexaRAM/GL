#ifndef DECLARATIONCONST_H 
#define DECLARATIONCONST_H

#include "declaration.h"
#include "num.h"
#include "identificateur.h"

	class DeclarationConst : public Declaration {
	protected:
		map<Identificateur*,Num*> map_const;
	public:
		DeclarationConst(): Declaration() {}
		void addConst(Identificateur* ident, Num* num);
		virtual ~DeclarationConst() {}
	};
#endif
