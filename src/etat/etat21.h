#if !defined ( Etat21_H )
#define Etat21_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat21 : public Etat {
		public: 	
			Etat21(string name);
			Etat21();
			virtual ~Etat21();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif