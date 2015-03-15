#if !defined ( Etat17_H )
#define Etat17_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat17 : public Etat {
		public: 	
			Etat17(string name);
			Etat17();
			virtual ~Etat17();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif
