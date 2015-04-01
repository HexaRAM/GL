#include "declarationConst.h"

DeclarationConst::~DeclarationConst()
{
    // suppression des constantes
    for (auto const &it : constantes)
    {
        delete it.ident;
        delete it.value;
    }
}


void DeclarationConst::addConst(Identificateur* ident, Num* num){
	constantes.push_back({ident, num});
}

void DeclarationConst::print(ostream& os) const {
	for (auto const &it : constantes)
    {
		os << "const " << *(it.ident) << " = " << *(it.value) << ";" << endl;
	}
}