#if !defined ( Etat43_H )
#define Etat43_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat43 : public Etat {
		public: 	
			Etat43(string name);
			Etat43();
			virtual ~Etat43();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif