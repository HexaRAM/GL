#if !defined ( Etat41_H )
#define Etat41_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat41 : public Etat {
		public: 	
			Etat41(string name);
			Etat41();
			virtual ~Etat41();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif