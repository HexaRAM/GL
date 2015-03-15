#if !defined ( Etat14_H )
#define Etat14_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat14 : public Etat {
		public: 	
			Etat14(string name);
			Etat14();
			virtual ~Etat14();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif