#include <iostream>
#include <string>
#include <boost/regex.hpp>
#include "commandLineReader.h"
#include "automate/automate.h"
using namespace std;

/**
 * @TODO
 *    - normaliser les sorties
 *    - faire un fichier config.h avec l'ensemble des constantes du projet
 */

int main(int argc, char ** argv)
{   
    CommandLineReader console(argc, argv);
    console.displayMode();
    Automate* automate = console.createAutomate();

    if (automate == NULL)
    {
        cout << "# La création de l'automate n'a pas été rendu possible." << endl;
        exit(1);
    }

    automate->addVariable("a");
    automate->addVariable("b");
    automate->addConstante("c", 69);
    automate->instanciateVariable("a", 100);
    automate->instanciateVariable("e", 200);
    automate->addVariable("c");
    automate->addConstante("b", 78);

    cout << "\tEtat de la mémoire : " << endl;
    automate->displayMemory();

    delete automate;
}