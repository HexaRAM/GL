#if !defined ( Etat34_H )
#define Etat34_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat34 : public Etat {
		public: 	
			Etat34(string name);
			Etat34();
			virtual ~Etat34();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif