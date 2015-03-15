#if !defined ( Etat22_H )
#define Etat22_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat22 : public Etat {
		public: 	
			Etat22(string name);
			Etat22();
			virtual ~Etat22();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif