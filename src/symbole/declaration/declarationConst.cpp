#include "declarationConst.h"

void DeclarationConst::addConst(Identificateur* ident, Num* num){
	map_const.push_back({ident, num});
}

void DeclarationConst::print(ostream& os) const {
	for(auto const &it : map_const){
		os << "const " << *(it.ident) << " = " << *(it.value) << ";" << endl;
	}
}