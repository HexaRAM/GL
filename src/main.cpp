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

    delete automate;
}