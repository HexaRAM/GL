#include "declarationConst.h"

void DeclarationConst::addConst(Identificateur* ident, Num* num){
	constantes.push_back({ident, num});
}

void DeclarationConst::print(ostream& os) const {
	for(auto const &it : constantes){
		os << "const " << *(it.ident) << " = " << *(it.value) << ";" << endl;
	}
}