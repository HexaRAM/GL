#include "opParenthese.h"

OpParenthese::OpParenthese(Expression* expression) {
	Expression();
	expr = expression;
}
double OpParenthese::eval(const map<string, double> &valeurs){
	return expr->eval(valeurs);
}