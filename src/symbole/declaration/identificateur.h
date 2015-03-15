#ifndef IDENTIFICATEUR_H 
#define IDENTIFICATEUR_H

#include "../symbole.h"

	class Identificateur : public Symbole {
		public:
			Identificateur(): Symbole(104) {}
			virtual ~Identificateur() {}
	};
#endif