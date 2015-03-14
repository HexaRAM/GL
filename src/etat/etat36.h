#if !defined ( Etat36_H )
#define Etat36_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat36 : public Etat {
		public: 	
			Etat36(string name);
			Etat36();
			virtual ~Etat36();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif