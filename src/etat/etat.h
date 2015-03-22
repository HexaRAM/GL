#if !defined ( ETAT_H )
#define ETAT_H

#include <string>
#include <map>
using namespace std;

#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "../config.h"


	class Etat {
		public: 	
			Etat(string name);
			Etat();
			virtual ~Etat();
			void print() const;
			virtual bool transition(Automate & automate, Symbole * s ) = 0;
			virtual bool getNextState(Symbole * s)=0;
		protected: 
			string name;
	};
#endif
