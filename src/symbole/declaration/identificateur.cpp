#include "identificateur.h"

Identificateur::Identificateur(string str){
	Expression(104);
	nom = str; 
}

ostream& operator<<(ostream& os, const Identificateur& dt){
	os<<dt.nom;
	return os;
}