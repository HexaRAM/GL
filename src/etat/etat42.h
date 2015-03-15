#if !defined ( Etat42_H )
#define Etat42_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat42 : public Etat {
		public: 	
			Etat42(string name);
			Etat42();
			virtual ~Etat42();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif