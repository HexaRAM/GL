#if !defined ( LEXER_H )
#define LEXER_H

#include <string>
#include <set>

#include "../symbole/symbole.h"
#include "../symbole/declaration/identificateur.h"

#define NB_REGEX 16
#define MAX_NO_PATTERN_SEQUENCE 10

class Lexer
{
    public:
        Lexer();
        ~Lexer();
        Symbole* getNext(string& buff);
        static string regex[];
    private:
        set<Identificateur*> idents;
};

#endif