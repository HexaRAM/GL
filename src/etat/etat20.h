#if !defined ( Etat20_H )
#define Etat20_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat20 : public Etat {
		public: 	
			Etat20(string name);
			Etat20();
			virtual ~Etat20();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif
