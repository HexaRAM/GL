#include "symbole.h"
#include "../config.h"

ostream& operator<<(ostream& os, const Symbole& dt){
	dt.print(os);
	return os;
}

bool Symbole::isOperator(Symbole* s)
{
    switch (*s)
    {
        case ct:
        case va:
        case af:
        case eg:
        case r:
        case w:
        case add:
        case moins:
        case fois:
        case divise:
            return true;
        break;

        default:
            return false;
        break;
    }
}

void Symbole::print(ostream& os) const
{
    //os << "SYMBOLE D'ORIGINE INCONNU" << endl;
    string s = "";
    switch (ident)
    {
        case 100:
            s = ";";
        break;

        case 101:
            s = "const";
        break;

        case 102:
            s = "var";
        break;

        case 103:
            s = ",";
        break;

        case 107:
            s = ":=";
        break;

        default:
        break;

    }
    if (s == "")
    {
        os << ident;
    }
    else
    {
        os << s;
    }
}