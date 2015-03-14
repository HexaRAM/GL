#if !defined ( Etat33_H )
#define Etat33_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat33 : public Etat {
		public: 	
			Etat33(string name);
			Etat33();
			virtual ~Etat33();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif