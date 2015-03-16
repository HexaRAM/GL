#ifndef BLOCDECLARATION_H 
#define BLOCDECLARATION_H

#include "../symbole.h"
#include "declaration.h"

#include <deque>

using namespace std;

	class BlocDeclaration : public Symbole {
	protected:
		deque<Declaration*> liste_declaration;
	public:
		BlocDeclaration(): Symbole(1) {}
		void addDeclaration(Declaration* d);
		virtual ~BlocDeclaration() {}
		void print();
	};
#endif
