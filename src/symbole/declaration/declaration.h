#ifndef DECLARATION_H 
#define DECLARATION_H

#include "../symbole.h"

	class Declaration : public Symbole {
	
	public:
		Declaration(): Symbole(2) {}
		virtual ~Declaration() {}
	};
#endif