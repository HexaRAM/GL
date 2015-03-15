#if !defined ( Etat26_H )
#define Etat26_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat26 : public Etat {
		public: 	
			Etat26(string name);
			Etat26();
			virtual ~Etat26();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif