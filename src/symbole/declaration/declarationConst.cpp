#include "declarationConst.h"

void DeclarationConst::addConst(Identificateur* ident, Num* num){
	map_const.insert(std::pair<Identificateur*,Num*>(ident,num));
}
