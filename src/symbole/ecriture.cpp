#include "ecriture.h"

using namespace std;

Ecriture::Ecriture(Expression e) : expr(e){
	Instruction(109);
}

void Ecriture::print(ostream& os) const {
	os<<"ecrire "<<expr<<";";
}

ostream& operator<<(ostream& os, const Ecriture& dt){
	dt.print(os);
	return os;
}