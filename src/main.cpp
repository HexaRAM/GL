#include <iostream>
#include <string>
#include <boost/regex.hpp>
using namespace std;

bool syntaxe_id(string id)
{
    boost::regex re("(?!(^var$|^const$|^ecrire$|^lire$))^[a-zA-Z][a-zA-Z0-9]*$");
    boost::cmatch matches;
    return boost::regex_match(id.c_str(), matches, re);
}
bool syntaxe_filename(string filename)
{
    //TODO
    return true;
}
bool syntaxe_options(string option)
{
    boost::regex re("(^-a$|^-o$|^-p$)");
    boost::cmatch matches;
    return boost::regex_match(option.c_str(), matches, re);
}


void execute_program(string filename, bool aff, bool ana, bool simpli)
{
    string modeStr = (aff) ? "AFFICHAGE (-p) " : "";
    modeStr += (ana) ? "ANALYSE (-a) " : "";
    modeStr += (simpli) ? "SIMPLIFICATION (-o) " : "";

    if (modeStr == "")
    {
        modeStr = "normal.";
    }
    cout << "# Lancement du programme en mode " << modeStr << endl;
}

/**
 * @TODO
 *    - mettre le parseur des arguments passés en console dans une classe dédiée
 *    - normaliser les sorties
 *    - faire un fichier config.h avec l'ensemble des constantes du projet
 */

int main(int argc, char ** argv)
{   
    //OPTIONS//
    string nom_fichier;
    bool AFFICHAGE = false;
    bool ANALYSE = false;
    bool SIMPLIFICATION = false;
    if(argc < 2)
        cout << "# Sans arguments" <<endl;
    else
    {
        if(syntaxe_filename(argv[1]))
        {
            nom_fichier = argv[1];
            cout << "nom fichier : " + nom_fichier <<endl;
            for(int i=2; i<argc;i++)
            {
                if(syntaxe_options(argv[i]))
                {
                 switch(argv[i][1])
                 {
                    case 'p':
                        AFFICHAGE = true;
                        break;
                    case 'a':
                        ANALYSE= true;
                        break;
                    case 'o':
                        SIMPLIFICATION = true;
                        break;
                    default:
                    break;
                 }
                }
                else
                {
                    cout << "# Option incorrecte : ";  
                    cout << argv[i] <<endl;
                }
            }
        }
        else
        {
            cout << "# Nom fichier incorrecte : ";     
            cout << argv[1] <<endl;
        }
        execute_program(nom_fichier, AFFICHAGE, ANALYSE, SIMPLIFICATION);
    }
    
    
    /*cout <<"Analyse syntaxique le nom des variables :" <<endl;
    string s;
    cin >> s;
    if(syntaxe_id(s))
    {
        cout<< "# match" << endl;
    }
    else
    {
     cout << "# no match" << endl;
    }*/

 }