#if !defined ( Etat23_H )
#define Etat23_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat23 : public Etat {
		public: 	
			Etat23(string name);
			Etat23();
			virtual ~Etat23();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif