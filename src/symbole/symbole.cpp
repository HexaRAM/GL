#include "symbole.h"

ostream& operator<<(ostream& os, const Symbole& dt){
	dt.print(os);
	return os;
}

void Symbole::print(ostream& os) const
{
	os << ident;
}