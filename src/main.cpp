#include <iostream>
#include <boost/regex.hpp>
using namespace std;

int main ()
{
	cout << "Coucou l'HexaRAM+" << endl;
    string pattern = "^\\d$";
    string text = "43";
    boost::regex re(pattern);

    bool test = boost::regex_match(text, re);

    if (test)
    {
        cout << "ça match !" << endl;
    }
    else 
    {
        cout << "ça ne match pas !" << endl;
    }

}
