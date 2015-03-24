#include "declarationConst.h"

void DeclarationConst::addConst(Identificateur* ident, Num* num){
	map_const.insert(std::pair<Identificateur*,Num*>(ident,num));
}

void DeclarationConst::print(ostream& os) const {

	for(auto const &it:map_const){
		os << "const " << *(it.first) << " = " << *(it.second) << ";" << endl;
	}
}