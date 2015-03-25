#include "lecture.h"

Lecture::Lecture(Identificateur* ident) {
	Instruction();
	id = ident;
}


void Lecture::print(ostream& os) const {
	os<<"lire " << *id << ";" << endl;
}