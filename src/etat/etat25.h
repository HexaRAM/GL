#if !defined ( Etat25_H )
#define Etat25_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat25 : public Etat {
		public: 	
			Etat25(string name);
			Etat25();
			virtual ~Etat25();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif