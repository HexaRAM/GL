#ifndef SYMBOLE_H 
#define SYMBOLE_H

#include <iostream>

using namespace std;

    class Symbole {
        protected:
            int ident;
        public:
            Symbole(int id) : ident(id) {}
            virtual ~Symbole() {}
            virtual void print(ostream& os) const;
            operator int() const { return ident; }
            friend ostream& operator<<(ostream& os, const Symbole& dt);
            static bool isOperator(Symbole*);
    };
#endif