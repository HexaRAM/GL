#if !defined ( Etat3_H )
#define Etat3_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat3 : public Etat {
		public: 	
			Etat3(string name);
			Etat3();
			virtual ~Etat3();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif