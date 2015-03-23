#ifndef OM_H 
#define OM_H

#include "symbole.h"
#include <string>

using namespace std;

	class om : public Symbole {
		protected: 
			string type; // multiplication ou division
		public:
			om(): Symbole(11) {}
			om(string t); 
			virtual ~om() {}			
	};
#endif