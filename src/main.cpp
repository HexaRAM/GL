#include <iostream>
#include <string>
#include <map>
#include "config.h"
#include "commandLineReader.h"
#include "automate/automate.h"
#include "config.h"

#include "symbole/ecriture.h"
#include "symbole/expr/exprMult.h"
#include "symbole/expr/exprPlus.h"
#include "symbole/expr/expression.h"
#include "symbole/declaration/identificateur.h"
#include "symbole/declaration/num.h"

using namespace std;

/**
 * @TODO
 *    - normaliser les sorties
 *    - faire un fichier config.h avec l'ensemble des constantes du projet
 */

int main(int argc, char** argv)
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
   

    /*
    cout<<"TestEval"<<endl;
    Identificateur* a = new Identificateur("a");
    Identificateur* b = new Identificateur("b");
    Num* c = new Num(4);
    map<string, double> valeurs;
    valeurs["a"] = 3;
    valeurs["b"] = 1;
    cout<<"eval a "<<a->eval(valeurs)<<endl;
    cout<<"eval b "<<b->eval(valeurs)<<endl;
    cout<<"eval c "<<c->eval(valeurs)<<endl;
    ExprMult* bc = new ExprMult(b,c);
    ExprPlus* abc = new ExprPlus(a,bc);
    cout<<"eval tout "<<abc->eval(valeurs)<<endl;
    */
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
    //         Symbole* next = automate->getNext();
    //         while (*next != ID_SYMBOLE::dollar && next != NULL)
    //         {
    //             cout << "# Prochain symbole : " << *next << endl;
    //             next = automate->getNext();

    //             if (*next == ID_SYMBOLE::dollar)
    //             {
    //                 cout << "# Prochain symbole : " << *next << endl << "\tFin de la lecture" << endl;
    //             }
    //         }

    //         if (next != NULL)
    //         {
    //             delete next;
    //         }
    //     }
    //     else
    //     {
    //         Symbole* next = automate->getNext();
    //         cout << "# Prochain symbole : " << *next << endl;
    //         if (next != NULL)
    //         {
    //             delete next;
    //         }
    //     }
    // }

    //delete automate;

}