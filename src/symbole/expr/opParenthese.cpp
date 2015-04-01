#include "opParenthese.h"

OpParenthese::OpParenthese(Expression* expression)
{
	Expression();
	expr = expression;
    ident = 9;
}

OpParenthese::~OpParenthese()
{
    delete expr;
}

double OpParenthese::eval(const map<string, double> &valeurs)
{
	return expr->eval(valeurs);
}

void OpParenthese::print(ostream& os) const 
{
	os << "(" << *expr << ")";
}

Expression* OpParenthese::neutralOpti()
{
    Expression* exprOpti = expr->neutralOpti();
    return new OpParenthese(exprOpti);
}

set<Identificateur*> OpParenthese::getIdents() const
{
    return expr->getIdents();
}