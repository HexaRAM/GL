#include "exprMult.h"
#include "../declaration/num.h"
#include <iostream>


using namespace std;

ostream& operator<<(ostream& os, const ExprMult& dt){
	os << *(dt.expr_gauche) << " * " << *(dt.expr_droite) << endl;
	return os;
}

double ExprMult::eval(const map<string, double> &valeurs){
	return ( expr_gauche->eval(valeurs) * expr_droite->eval(valeurs));
}

Expression* ExprMult::neutralOpti(){
	Num* numGauche = dynamic_cast<Num*>(expr_gauche);
	Num* numDroite = dynamic_cast<Num*>(expr_droite);

	if (numGauche != NULL && (int)(*numGauche) == 1)
	{
		return expr_droite->neutralOpti();
	}
	else if(numDroite != NULL && (int)(*numDroite) == 1)
	{
		return expr_gauche->neutralOpti();
	}
	else
	{
		Expression* expr_gaucheOpti = expr_gauche->neutralOpti();
		Expression* expr_droiteOpti = expr_droite->neutralOpti();

		return new ExprMult(expr_gaucheOpti, expr_droiteOpti);
	}
}


void ExprMult::print(ostream& os) const {
	os << *expr_gauche << "*" << *expr_droite;
}