#if !defined ( ETAT0_H )
#define ETAT0_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat0 : public Etat {
		public: 	
			Etat0(string name);
			Etat0();
			virtual ~Etat0();
			Etat* next(Symbole* s);
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif