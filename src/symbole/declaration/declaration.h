#ifndef DECLARATION_H 
#define DECLARATION_H

#include "../symbole.h"

	class Declaration : public Symbole {
	
	public:
		Declaration(): Symbole(2) {}
        Declaration(int identifiant) : Symbole(identifiant) {}
		virtual void declarationFinie()=0;
		virtual ~Declaration() {}
	};
#endif