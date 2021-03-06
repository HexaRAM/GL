#include "exprMoins.h"
#include "../declaration/num.h"

double ExprMoins::eval(const map<string, double> &valeurs) {
	return ( expr_gauche->eval(valeurs) - expr_droite->eval(valeurs));
	
}

Expression* ExprMoins::neutralOpti(){
	Num* numGauche = dynamic_cast<Num*>(expr_gauche);
	Num* numDroite = dynamic_cast<Num*>(expr_droite);

	if (numGauche != NULL && (int)(*numGauche) == 0)
	{
		return expr_droite->neutralOpti();
	}
	else if(numDroite != NULL && (int)(*numDroite) == 0)
	{
		return expr_gauche->neutralOpti();
	}
	else
	{
		Expression* expr_gaucheOpti = expr_gauche->neutralOpti();
		Expression* expr_droiteOpti = expr_droite->neutralOpti();

		return new ExprMoins(expr_gaucheOpti, expr_droiteOpti);
	}
}

void ExprMoins::print(ostream& os) const {
	os << *expr_gauche << "-" << *expr_droite;
}