#if !defined ( Etat10_H )
#define Etat10_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat10 : public Etat {
		public: 	
			Etat10(string name);
			Etat10();
			virtual ~Etat10();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif