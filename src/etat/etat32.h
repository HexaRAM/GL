#if !defined ( Etat32_H )
#define Etat32_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat32 : public Etat {
		public: 	
			Etat32(string name);
			Etat32();
			virtual ~Etat32();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif