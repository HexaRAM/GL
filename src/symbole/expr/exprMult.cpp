#include "exprMult.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& os, const ExprMult& dt){
	os << *(dt.expr_gauche) << " * " << *(dt.expr_droite) << endl;
	return os;
}

double ExprMult::eval(const map<string, double> &valeurs){
	return ( expr_gauche->eval(valeurs) * expr_droite->eval(valeurs));
}

void ExprMult::print(ostream& os) const {
	os << *expr_gauche << " * " << *expr_droite;
}