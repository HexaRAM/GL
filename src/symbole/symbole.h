#ifndef SYMBOLE_H 
#define SYMBOLE_H
    class Symbole {
        protected:
            int ident;
        public:
            Symbole(int id) : ident(id) {}
            virtual ~Symbole() {}
            void print();
            operator int() const { return ident; }
            //friend ostream& operator<<(ostream& os, const Date& dt);
    };
#endif