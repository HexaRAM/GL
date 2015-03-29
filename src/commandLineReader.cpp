#include "commandLineReader.h"
#include "config.h"
#include <iostream>
#include <iterator>
#include <fstream>
#include <boost/regex.hpp>

/**
 * Constructeur
 */
CommandLineReader::CommandLineReader(int argc, char** argv)
{

    // init
    this->enableCreationOfAutomate = false;
    this->affichage = false;
    this->analyse = false;
    this->optimisation = false;
    this->execution = false;
    this->nomFichier = "";

    // parse
    if(argc < 2)
    {
        #ifdef DEBUG
            cout << "# Sans arguments" << endl;
        #endif
        usage();
        exit(1);
    }
    else
    {
        if (syntaxe_filename(argv[argc-1]))
        {
            this->nomFichier = argv[argc-1];

            for (unsigned int i=1; i<(unsigned int)argc-1;i++)
            {
                // si l'argument i match une option, on la rajoute
                if (syntaxe_options(argv[i]))
                {
                 switch(argv[i][1])
                 {
                    case 'p':
                        this->affichage = true;
                    break;

                    case 'a':
                        this->analyse = true;
                    break;

                    case 'o':
                        this->optimisation = true;
                    break;

                    case 'e':
                        this->execution = true;
                    break;

                    default:

                    break;
                 }
                }
                else
                {
                    
                    cerr << "# Option incorrecte : " << argv[i] << endl;
                    exit(1);
                }
            }

            this->enableCreationOfAutomate = true;
        }
        else
        {   
            string str(argv[argc-1]);
            cerr << "Erreur a l'ouverture du fichier " << str << endl;
            exit(1);
        }
    }
}

/**
 * Destructeur
 */
CommandLineReader::~CommandLineReader()
{

}

/**
 * Public methods
 */
Automate* CommandLineReader::createAutomate()
{
    if (this->enableCreationOfAutomate)
    {
        ifstream fichier(this->nomFichier.c_str());
        string code = "";
        vector<int> linesBreaks;
        while (!fichier.fail())
        {
            string tmp;
            getline(fichier, tmp); // lire une ligne
            linesBreaks.push_back(tmp.size());
            code += tmp;
        }
        fichier.close();

        Automate* automate = new Automate(this->affichage, this->analyse, this->optimisation, this->execution, code, linesBreaks);
        return automate;
    }
    return NULL;
}

void CommandLineReader::displayMode()
{
    string modeStr = (this->affichage) ? "AFFICHAGE (-p) " : "";
    modeStr += (this->analyse) ? "ANALYSE (-a) " : "";
    modeStr += (this->optimisation) ? "SIMPLIFICATION (-o) " : "";
    modeStr += (this->execution) ? "EXECUTION (-e) " : "";

    if (modeStr == "")
    {
        modeStr = "normal.";
    }
    #ifdef DEBUG
        cout << "# Programme lancé en mode " << modeStr << endl;
    #endif
}

/**
 * Private methods
 */

void CommandLineReader::usage()
{
    cerr << "Erreur, veuillez specifier des arguments" << endl <<
        "  Utilisation :" << endl <<
        "    ../lut [-p] [-a] [-e] [-o] source.lt" << endl <<
        "      [-p] affiche le code source reconnu" << endl <<
        "      [-a] analyse le programme de maniere statique" << endl <<
        "      [-e] execute interactivement le programme" << endl <<
        "      [-o] optimise les expressions et instructions" << endl;
}

bool CommandLineReader::syntaxe_filename (const string& filename)
{
    ifstream fichier(filename.c_str());
    if (fichier.good())
    {
        fichier.close();
        return true;
    }
    fichier.close();
    return false;
}

bool CommandLineReader::syntaxe_options (const string& option)
{
    boost::regex re("(^-a$|^-o$|^-p$|^-e$)");
    boost::cmatch matches;
    return boost::regex_match(option.c_str(), matches, re);
}