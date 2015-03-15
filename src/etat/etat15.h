#if !defined ( Etat15_H )
#define Etat15_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat15 : public Etat {
		public: 	
			Etat15(string name);
			Etat15();
			virtual ~Etat15();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif