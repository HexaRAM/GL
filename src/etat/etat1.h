#if !defined ( Etat1_H )
#define Etat1_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat1 : public Etat {
		public: 	
			Etat1(string name);
			virtual ~Etat1();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif