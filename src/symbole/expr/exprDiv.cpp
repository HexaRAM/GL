#include "exprDiv.h"

double ExprDiv::eval(const map<string, double> &valeurs){
	return ( expr_gauche->eval(valeurs) / expr_droite->eval(valeurs));
}