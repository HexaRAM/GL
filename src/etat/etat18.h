#if !defined ( Etat18_H )
#define Etat18_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat18 : public Etat {
		public: 	
			Etat18(string name);
			Etat18();
			virtual ~Etat18();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif
