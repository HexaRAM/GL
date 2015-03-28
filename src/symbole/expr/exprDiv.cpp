#include "exprDiv.h"
#include "../declaration/num.h"

double ExprDiv::eval(const map<string, double> &valeurs){
	if(expr_droite->eval(valeurs) != 0) {
		return ( expr_gauche->eval(valeurs) / expr_droite->eval(valeurs));
	}
	return 0;
}

Expression * ExprDiv::neutralOpti(){
	Num* numGauche = dynamic_cast<Num*>(expr_gauche);
	Num* numDroite = dynamic_cast<Num*>(expr_droite);
	if (numGauche!=NULL && (int)numGauche == 1)
		return expr_droite;
	else if(numDroite != NULL && (int)numDroite == 1)
		return expr_gauche;
	else
		//pas d'optimisation à faire
		return NULL;
}

void ExprDiv::print(ostream& os) const {
	os << *expr_gauche << "/" << *expr_droite;
}