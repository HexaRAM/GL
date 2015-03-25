#include "declarationVar.h"

void DeclarationVar::addIdentificateur(Identificateur* ident){
	liste_identif.push_back(ident);
	}

void DeclarationVar::print(ostream& os) const {
	for(auto const &it : liste_identif){
		os << "var " << *it << ";" << endl;
	}
}