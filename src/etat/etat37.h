#if !defined ( Etat37_H )
#define Etat37_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat37 : public Etat {
		public: 	
			Etat37(string name);
			Etat37();
			virtual ~Etat37();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif