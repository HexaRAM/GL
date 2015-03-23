#include "exprBin.h"

ExprBin::ExprBin(Expression* gauche, Expression* droite){
	Expression();
	expr_gauche = gauche;
	expr_droite = droite;
}
