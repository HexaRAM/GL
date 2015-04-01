#include "identificateur.h"

double Identificateur::eval(const map<string, double> &valeurs)
{
	auto it = valeurs.find(nom);

	if (it == valeurs.end())
    {
  		// not found
  		return 0;
	} 
  	return it->second;
}

Expression* Identificateur::neutralOpti()
{
    Identificateur* identifOpti = new Identificateur(nom);
    return identifOpti;
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

set<string> Identificateur::idents;

bool Identificateur::checkDouble(const string& name)
{
    if (Identificateur::idents.find(name) != Identificateur::idents.end())
    {
        cerr << "la variable " << name << " est deja declaree" << endl;
        return false;
    }
    Identificateur::idents.insert(name);
    return true;
}