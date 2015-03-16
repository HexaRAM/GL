#ifndef NUM_H 
#define NUM_H

#include "../expr/expression.h"

	class Num : public Expression {
		public:
			Num(): Expression(106) {}
			virtual ~Num() {}
	};
#endif
