#include "exprMult.h"

double ExprMult::eval(const map<string, double> &valeurs){
	return ( expr_gauche->eval(valeurs) * expr_droite->eval(valeurs));
}