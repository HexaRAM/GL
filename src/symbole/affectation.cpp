#include "affectation.h"

Affectation::Affectation(Expression* expression, Identificateur* ident) {
	Instruction(107);
	expr = expression;
	id = ident;
}

void Affectation::print(ostream& os) const {
	//TODO
}