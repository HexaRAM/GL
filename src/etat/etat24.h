#if !defined ( Etat24_H )
#define Etat24_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat24 : public Etat {
		public: 	
			Etat24(string name);
			Etat24();
			virtual ~Etat24();
			Etat* next(Symbole* s);
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif