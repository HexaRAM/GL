#include "exprMult.h"
#include <iostream>

using namespace std;

void ExprMult::print(ostream& os) const{
	os<<expr_gauche<<"*"<<expr_droite;
}

ostream& operator<<(ostream& os, const ExprMult& dt){
	os << *(dt.expr_gauche) << " * " << *(dt.expr_droite) << endl;
	//dt.print(os);
	return os;
}