#include "exprBin.h"

ExprBin::ExprBin(Expression* gauche, Expression* droite)
{
	Expression();
	expr_gauche = gauche;
	expr_droite = droite;
}

void ExprBin::print(ostream& os) const 
{
	// expression binaire inconnue
}

Expression* ExprBin::getExprGauche(){
	return expr_gauche;
}
Expression* ExprBin::getExprDroite(){
	return expr_droite;
}

Expression* getExprDroite();
