#include "affectation.h"

Affectation::Affectation(Expression* expression, Identificateur* ident) {
	Instruction(107);
	expr = expression;
	id = ident;
}

void Affectation::print(ostream& os) const {
	os << *id << " := " << *expr << ";" << endl;
}

Expression* Affectation::getExpression(){
	return expr;
}

Identificateur* Affectation::getIndentificateur(){
	return id;
}