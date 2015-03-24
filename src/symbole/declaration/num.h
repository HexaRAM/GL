#ifndef NUM_H 
#define NUM_H

#include "../expr/expression.h"

	class Num : public Expression {
		protected:
			int valeur;
		public:
			Num(): Expression(106) {}
			Num(int val);
			double eval(const map<string, double> &valeurs);
			virtual ~Num() {}
			virtual void print(ostream& os) const;
	};
#endif
