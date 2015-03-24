#if !defined ( Etat13_H )
#define Etat13_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat13 : public Etat {
		public: 	
			Etat13(string name);
			Etat13();
			virtual ~Etat13();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif