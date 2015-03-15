#if !defined ( Etat27_H )
#define Etat27_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat27 : public Etat {
		public: 	
			Etat27(string name);
			Etat27();
			virtual ~Etat27();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif