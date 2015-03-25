#include "exprDiv.h"

double ExprDiv::eval(const map<string, double> &valeurs){
	return ( expr_gauche->eval(valeurs) / expr_droite->eval(valeurs));
}

void ExprDiv::print(ostream& os) const {
	os << *expr_gauche << "/" << *expr_droite;
}