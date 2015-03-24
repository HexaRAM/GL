#include "exprBin.h"

ExprBin::ExprBin(Expression* gauche, Expression* droite){
	Expression();
	expr_gauche = gauche;
	expr_droite = droite;
	}

void ExprBin::print(ostream& os) const {
	//TODO
}