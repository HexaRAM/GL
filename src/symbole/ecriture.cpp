#include "ecriture.h"

Ecriture::Ecriture(Expression* e) : expr(e)
{
	Instruction();
}

Ecriture::~Ecriture()
{
    delete expr;
}

void Ecriture::print(ostream& os) const
{
	os << "ecrire " << *expr << ";";
}
Expression* Ecriture::getExpression()
{
	return expr;
}

void Ecriture::setExpression(Expression* expression)
{
	if(expr != NULL)
    {
		delete expr;
    }
	expr = expression;
}
