#ifndef DECLARATIONCONST_H 
#define DECLARATIONCONST_H

#include "declaration.h"
#include "Num.h"
#include "Identificateur.h"

	class DeclarationConst : public Declaration {
	protected:
		map<Identificateur,Num> map_const;
	public:
		DeclarationConst() {}
		virtual ~DeclarationConst() {}
	};
#endif