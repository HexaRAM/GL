#if !defined ( LEXER_H )
#define LEXER_H

#include <string>
#include <set>
#include <vector>

#include "../symbole/symbole.h"
#include "../symbole/declaration/identificateur.h"

#define NB_REGEX 16
#define MAX_NO_PATTERN_SEQUENCE 10

class Lexer
{
    public:
        Lexer();
        Lexer(vector<int> linesBreaks);
        ~Lexer();
        Symbole* getNext(string& buff);
        static string regex[];
    private:
        int charRead;
        set<Identificateur*> idents;
        vector<int> linesBreaks;

        void getCurrentLineAndColumn(int& line, int& column);
};

#endif