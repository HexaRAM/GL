#include "exprDiv.h"

double ExprDiv::eval(const map<string, double> &valeurs){
	if(expr_droite->eval(valeurs) != 0) {
		return ( expr_gauche->eval(valeurs) / expr_droite->eval(valeurs));
	}
	return 0;
}

void ExprDiv::print(ostream& os) const {
	os << *expr_gauche << "/" << *expr_droite;
}