#if !defined ( Etat35_H )
#define Etat35_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat35 : public Etat {
		public: 	
			Etat35(string name);
			Etat35();
			virtual ~Etat35();
			Etat* next(Symbole* s);
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif