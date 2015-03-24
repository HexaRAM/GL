#if !defined ( Etat4_H )
#define Etat4_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat4 : public Etat {
		public: 	
			Etat4(string name);
			Etat4();
			virtual ~Etat4();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif