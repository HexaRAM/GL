#include "affectation.h"

Affectation::Affectation(Expression* expression, Identificateur* ident) {
	Instruction(107);
	expr = expression;
	id = ident;
}

void Affectation::print(ostream& os) const {
	os << *id << " := " << *expr << ";";
}

Expression* Affectation::getExpression()
{
	return expr;
}

Identificateur* Affectation::getIdentificateur()
{
	return id;
}

void Affectation::setExpression(Expression* expression)
{
	if(expr != NULL)
		delete expr;
	expr = expression;

}
