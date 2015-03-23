#if !defined ( ETAT_H )
#define ETAT_H

#include <string>
#include <map>
using namespace std;

//#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "../config.h"

class Automate;

	class Etat {
		public: 	
			Etat(string name);
			Etat();
			virtual ~Etat();
			virtual Etat* next(Symbole* s) { return NULL; } // aller à -> pour les réductions
			void print() const;
			virtual bool transition(Automate & automate, Symbole* s ) = 0;
			friend ostream& operator<<(ostream& os, const Etat& e);
		protected: 
			string name;
	};
#endif
