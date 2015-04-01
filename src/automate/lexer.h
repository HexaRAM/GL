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
        int getLine() { return line; }
        int getColumn() { return column; }
        static string regex[];
    private:
        int line;
        int column;
        int charRead;
        vector<int> linesBreaks;

        void getCurrentLineAndColumn(int& line, int& column);
};

#endif