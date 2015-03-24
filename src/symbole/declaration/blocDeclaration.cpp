#include "blocDeclaration.h"

void BlocDeclaration::addDeclaration(Declaration* d){
	liste_declaration.push_front(d);
}

void BlocDeclaration::print(ostream& os) const {
	for(auto const &it:liste_declaration){
		os << *it;
	}
}