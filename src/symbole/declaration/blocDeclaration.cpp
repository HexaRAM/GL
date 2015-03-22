#include "blocDeclaration.h"

void BlocDeclaration::addDeclaration(Declaration* d){
	liste_declaration.push_front(d);
}
