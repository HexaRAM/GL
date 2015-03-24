#if !defined ( Etat7_H )
#define Etat7_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat7 : public Etat {
		public: 	
			Etat7(string name);
			Etat7();
			virtual ~Etat7();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif