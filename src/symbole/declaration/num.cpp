#include "num.h"

double Num::eval(const map<string, double> &valeurs)
{
	return valeur;
}

Expression* Num::neutralOpti()
{
	Num* numOpti = new Num(valeur);
	return numOpti;
}

void Num::print(ostream& os) const {
	os<<valeur;
}