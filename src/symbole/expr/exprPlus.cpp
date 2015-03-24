#include "exprPlus.h"

double ExprPlus::eval(const map<string, double> &valeurs){
	return ( expr_gauche->eval(valeurs) + expr_droite->eval(valeurs));
}

void ExprPlus::print(ostream& os) const {
	//TODO
}