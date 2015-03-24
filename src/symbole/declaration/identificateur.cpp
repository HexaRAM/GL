#include "identificateur.h"

Identificateur::Identificateur(string str){
	Expression(104);
	nom = str; 
}

double Identificateur::eval(const map<string, double> &valeurs){
	auto it = valeurs.find(nom);

	if ( it == valeurs.end() ) {
  		// not found
  		return 0;
	} 
  	return it->second;
}

void Identificateur::print(ostream& os) const {
	os<<nom;
}