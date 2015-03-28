#include "exprDiv.h"
#include "../declaration/num.h"

double ExprDiv::eval(const map<string, double> &valeurs){
	if(expr_droite->eval(valeurs) != 0) {
		return ( expr_gauche->eval(valeurs) / expr_droite->eval(valeurs));
	}
	return 0;
}

Expression* ExprDiv::neutralOpti(){
	Num* numDroite = dynamic_cast<Num*>(expr_droite);
	if (numDroite != NULL && (int)(*numDroite) == 1)
	{
		return expr_gauche->neutralOpti();
	}
	else
	{
		Expression* expr_gaucheOpti = expr_gauche->neutralOpti();
		Expression* expr_droiteOpti = expr_droite->neutralOpti();

		return new ExprDiv(expr_gaucheOpti, expr_droiteOpti);
	}
}

void ExprDiv::print(ostream& os) const {
	os << *expr_gauche << "/" << *expr_droite;
}