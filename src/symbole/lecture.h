#ifndef LECTURE_H 
#define LECTURE_H

#include "instruction.h"
#include "declaration/identificateur.h"

	class  Lecture : public Instruction {
		protected:
			Identificateur* id;
		public:
			Lecture(): Instruction(){}
			Lecture(Identificateur* ident);
			virtual ~Lecture() {}
			void print(ostream& os) const;
	};
#endif
