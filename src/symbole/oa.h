#ifndef OA_H 
#define OA_H

#include "symbole.h"
#include <string>

using namespace std;

	class oa : public Symbole {
		protected: 
			string type; // addition ou substraction
		public:
			oa(): Symbole(10) {}
			oa(string t); 
			virtual ~oa() {}			
	};
#endif
