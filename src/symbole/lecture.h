#ifndef LECTURE_H 
#define LECTURE_H

#include "instruction.h"
#include "expr/variable.h"

	class  Lecture : public Instruction{
		protected:
			Variable var;
		public:
			Lecture(){}
			virtual ~Lecture() {}
			void print();
	};
#endif