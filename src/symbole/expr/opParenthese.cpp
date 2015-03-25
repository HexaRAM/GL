#include "opParenthese.h"

OpParenthese::OpParenthese(Expression* expression) {
	Expression();
	expr = expression;
    ident = 9;
}
double OpParenthese::eval(const map<string, double> &valeurs){
	return expr->eval(valeurs);
}

void OpParenthese::print(ostream& os) const {
	os << "(" << *expr << ")";
}
