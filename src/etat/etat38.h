#if !defined ( Etat38_H )
#define Etat38_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat38 : public Etat {
		public: 	
			Etat38(string name);
			Etat38();
			virtual ~Etat38();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif