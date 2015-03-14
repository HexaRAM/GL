#if !defined ( Etat39_H )
#define Etat39_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat39 : public Etat {
		public: 	
			Etat39(string name);
			Etat39();
			virtual ~Etat39();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif