#if !defined ( Etat6_H )
#define Etat6_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat6 : public Etat {
		public: 	
			Etat6(string name);
			Etat6();
			virtual ~Etat6();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif