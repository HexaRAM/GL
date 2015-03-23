#include "identificateur.h"

Identificateur::Identificateur(string str){
	Expression(104);
	nom = str; 
}

ostream& operator<<(ostream& os, const Identificateur& dt){
	os<<dt.nom;
	return os;
}

double Identificateur::eval(const map<string, double> &valeurs){
	auto it = valeurs.find(nom);

	if ( it == valeurs.end() ) {
  		// not found
  		return 0;
	} 
  	return it->second;
}