#ifndef NUM_H 
#define NUM_H

#include "../expr/expression.h"

	class Num : public Expression {
		public:
			Num(){}
			virtual ~Num() {}
	};
#endif