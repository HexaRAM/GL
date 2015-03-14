#if !defined ( Etat2_H )
#define Etat2_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat2 : public Etat {
		public: 	
			Etat2(string name);
			Etat2();
			virtual ~Etat2();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif