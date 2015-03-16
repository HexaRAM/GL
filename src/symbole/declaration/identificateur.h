#ifndef IDENTIFICATEUR_H 
#define IDENTIFICATEUR_H

#include "../expr/expression.h"

	class Identificateur : public Expression {
		public:
			Identificateur(): Expression(104) {}
			virtual ~Identificateur() {}
	};
#endif
