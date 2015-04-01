#include "expression.h"

double Expression::eval(const map<string, double> &valeurs)
{
	return 0;
}

Expression* Expression::neutralOpti()
{
	return NULL;
}

void Expression::print(ostream& os) const {
	// expression inconnue
}

set<Identificateur*> Expression::getIdents() const
{
    set<Identificateur*> idents;
    return idents;
}