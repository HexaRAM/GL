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

set<Identificateur*>  ExprBin::getIdents() const
{
    set<Identificateur*> idents1 = expr_gauche->getIdents();
    set<Identificateur*> idents2 = expr_droite->getIdents();

    // merge idents1 & idents2
    idents1.insert(idents2.begin(), idents2.end());
    return idents1;
}
