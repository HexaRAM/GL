#if !defined ( Etat5_H )
#define Etat5_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat5 : public Etat {
		public: 	
			Etat5(string name);
			Etat5();
			virtual ~Etat5();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif