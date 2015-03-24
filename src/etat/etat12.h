#if !defined ( Etat12_H )
#define Etat12_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat12 : public Etat {
		public: 	
			Etat12(string name);
			Etat12();
			virtual ~Etat12();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif