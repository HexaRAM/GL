#if !defined ( Etat40_H )
#define Etat40_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat40 : public Etat {
		public: 	
			Etat40(string name);
			Etat40();
			virtual ~Etat40();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif		