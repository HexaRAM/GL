#ifndef UNKNOWN_H 
#define UNKNOWN_H

    #include "symbole.h"

    class Unknown : public Symbole {
        private:
            char valeur;
        public:
            Unknown() : Symbole(1000) {}
            Unknown(char val) : Symbole(1000), valeur(val) {}
            
            char getValeur() { return valeur; }
            virtual ~Unknown() {}
            void print(ostream& os) const;

    };
#endif
