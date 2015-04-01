#include "blocDeclaration.h"

BlocDeclaration::~BlocDeclaration()
{
    for (auto const &it : liste_declaration)
    {
        delete it;
    }
}

void BlocDeclaration::addDeclaration(Declaration* d){
	liste_declaration.push_back(d);
}

void BlocDeclaration::print(ostream& os) const {
	for (auto const &it : liste_declaration)
    {
		os << *it;
	}
}