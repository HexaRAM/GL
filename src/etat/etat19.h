#if !defined ( Etat19_H )
#define Etat19_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat19 : public Etat {
		public: 	
			Etat19(string name);
			Etat19();
			virtual ~Etat19();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif
