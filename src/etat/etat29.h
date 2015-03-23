#if !defined ( Etat29_H )
#define Etat29_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat29 : public Etat {
		public: 	
			Etat29(string name);
			Etat29();
			virtual ~Etat29();
			Etat* next(Symbole* s);
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif