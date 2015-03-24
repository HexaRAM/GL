#include "ecriture.h"

using namespace std;

Ecriture::Ecriture(Expression* e) : expr(e){
	Instruction();
}

void Ecriture::print(ostream& os) const {
	os << "ecrire " << *expr << ";" << endl;
}