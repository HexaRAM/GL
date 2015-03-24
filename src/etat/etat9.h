#if !defined ( Etat9_H )
#define Etat9_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat9 : public Etat {
		public: 	
			Etat9(string name);
			Etat9();
			virtual ~Etat9();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif