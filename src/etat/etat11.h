#if !defined ( Etat11_H )
#define Etat11_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat11 : public Etat {
		public: 	
			Etat11(string name);
			Etat11();
			virtual ~Etat11();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif