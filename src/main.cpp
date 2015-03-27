#include "commandLineReader.h"
#include "automate/automate.h"
#include "config.h"

#include <iostream>
using namespace std;

int main(int argc, char** argv)
{   
    #ifdef DEBUG
        cout << "# Le mode DEBUG est activé !" << endl << endl;
    #endif

    CommandLineReader console(argc, argv);

    #ifdef DEBUG
        console.displayMode();
    #endif

    Automate* automate = console.createAutomate();

    if (automate == NULL)
    {
        exit(1);
    }

    automate->execute();
    delete automate;

}