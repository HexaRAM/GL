#if !defined ( Etat31_H )
#define Etat31_H

#include <string>
#include "../automate/automate.h"
#include "../symbole/symbole.h"
#include "etat.h"

using namespace std;


	class Etat31 : public Etat {
		public: 	
			Etat31(string name);
			Etat31();
			virtual ~Etat31();
			void print() const;
			bool transition(Automate & automate, Symbole * s );
		protected: 
			string name;
	};
#endif