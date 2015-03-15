#if !defined ( Etat8_H )
#define Etat8_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat8 : public Etat {
		public: 	
			Etat8(string name);
			Etat8();
			virtual ~Etat8();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif