#ifndef BLOCDECLARATION_H 
#define BLOCDECLARATION_H

#include "../symbole.h"
#include "declaration.h"

#include <vector>
#include <map>

using namespace std;

	class BlocDeclaration : public Symbole {
	protected:
		vector<Declaration*> liste_declaration;
	public:
		BlocDeclaration(): Symbole(1) {}
		void addDeclaration(Declaration* d);
		virtual ~BlocDeclaration() {}
		void print(ostream& os) const;
		map<string, double> getAllConstants();
		vector<Declaration*> getListeDeclaration() { return liste_declaration; }
	};
#endif
