#include "lecture.h"

Lecture::Lecture(Identificateur* ident)
{
	Instruction();
	id = ident;
}

Lecture::~Lecture()
{
    delete id;
}

void Lecture::print(ostream& os) const
{
	os << "lire " << *id << ";";
}
Identificateur* Lecture::getIdentificateur()
{
	return id;
}