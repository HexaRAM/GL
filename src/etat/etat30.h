#if !defined ( Etat30_H )
#define Etat30_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat30 : public Etat {
		public: 	
			Etat30(string name);
			Etat30();
			virtual ~Etat30();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif