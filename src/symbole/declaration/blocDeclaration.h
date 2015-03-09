#ifndef BLOCDECLARATION_H 
#define BLOCDECLARATION_H

#include "../symbole.h"
#include "declaration.h"

#include <deque.h>

using namespace std;

	class BlocDeclaration : public Symbole {
	protected:
		deque<Declaration> liste_declaration;
	public:
		BlocDeclaration() {}
		virtual ~BlocDeclaration() {}
		void print();
	};
#endif