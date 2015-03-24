#if !defined ( Etat16_H )
#define Etat16_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat16 : public Etat {
		public: 	
			Etat16(string name);
			Etat16();
			virtual ~Etat16();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif
