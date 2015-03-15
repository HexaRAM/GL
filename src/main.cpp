#include <iostream>
#include <string>
#include "config.h"
#include "commandLineReader.h"
#include "automate/automate.h"
#include "config.h"
using namespace std;

/**
 * @TODO
 *    - normaliser les sorties
 *    - faire un fichier config.h avec l'ensemble des constantes du projet
 */

int main(int argc, char ** argv)
{   

    #ifdef DEBUG
        cout << "# Le mode DEBUG est activé !" << endl << endl;
    #endif

    CommandLineReader console(argc, argv);
    console.displayMode();
    Automate* automate = console.createAutomate();

    if (automate == NULL)
    {
        cout << "# La création de l'automate n'a pas été rendu possible." << endl;
        exit(1);
    }

    automate->execute();

    // automate->addVariable("a");
    // automate->addVariable("b");
    // automate->addConstante("c", 69);
    // automate->instanciateVariable("a", 100);
    // automate->instanciateVariable("e", 200);
    // automate->addVariable("c");
    // automate->addConstante("b", 78);

    // cout << "\tEtat de la mémoire : " << endl;
    // automate->displayMemory();

    // // test Lexer


    // string press;
    // while (true)
    // {
    //     cout << endl;
    //     cout << "--------------------" << endl;
    //     cout << "------- MENU -------" << endl;
    //     cout << "--------------------" << endl;
    //     cout << "a : affichage code" << endl;
    //     cout << "b : display buffer" << endl;
    //     cout << "s : stop program" << endl;
    //     cout << "n : display all next " << endl;
    //     cout << "--------------------" << endl;
    //     cout << " > ";
    //     getline(cin, press);
    //     cout << endl;

    //     if (press == "s")
    //     {
    //         break;
    //     }
    //     else if (press == "a")
    //     {
    //         automate->execute(AFFICHAGE);
    //     }
    //     else if (press == "b")
    //     {
    //         automate->displayBuffer();
    //     }
    //     else if (press == "n")
    //     {
    //         string next = automate->getNext();
    //         while (next != "$" && next != "Erreur - aucun pattern trouvé")
    //         {
    //             cout << "# Prochain symbole : " << next << endl;
    //             next = automate->getNext();

    //             if (next == "$")
    //             {
    //                 cout << "# Prochain symbole : " << next << endl << "\tFin de la lecture" << endl;
    //             }
    //         }
    //     }
    //     else
    //     {
    //         string next = automate->getNext();
    //         cout << "# Prochain symbole : " << next << endl;
    //     }
    // }



    delete automate;
}