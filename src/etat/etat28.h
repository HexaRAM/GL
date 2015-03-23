#if !defined ( Etat28_H )
#define Etat28_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat28 : public Etat {
		public: 	
			Etat28(string name);
			Etat28();
			virtual ~Etat28();
			Etat* next(Symbole* s);
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif