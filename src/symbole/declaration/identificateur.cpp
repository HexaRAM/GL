#include "identificateur.h"

double Identificateur::eval(const map<string, double> &valeurs)
{
	auto it = valeurs.find(nom);

	if ( it == valeurs.end() ) {
  		// not found
  		return 0;
	} 
  	return it->second;
}

void Identificateur::print(ostream& os) const 
{
	os<<nom;
}

set<Identificateur*> Identificateur::getIdents() const
{
    set<Identificateur*> idents;
    Identificateur* id = (Identificateur*) this;
    idents.insert(id);
    return idents;
}