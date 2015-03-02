#include "commandLineReader.h"
#include <iostream>
#include <iterator>
#include <fstream>
#include <boost/regex.hpp>

/**
 * @TODO
 *     - remove options attributes
 *     - add options attributes to Automate class
 *     - build Automate here or in factory class !
 */

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
        cout << "# Sans arguments" << endl;
    else
    {
        if (syntaxe_filename(argv[1]))
        {
            this->nomFichier = argv[1];

            for (unsigned int i=2; i<(unsigned int)argc;i++)
            {
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
                    cout << "# Option incorrecte : " << argv[i] << endl;
                }
            }

            this->enableCreationOfAutomate = true;
        }
        else
        {
            cout << "# Nom fichier incorrecte : " << argv[1] << endl;
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
        while (!fichier.fail())
        {
            string tmp;
            fichier >> tmp;
            code += tmp;
        }
        //(istreambuf_iterator<char>(fichier), istreambuf_iterator<char>());
        fichier.close();

        Automate* automate = new Automate(this->affichage, this->analyse, this->optimisation, this->execution, code);
        return automate;
    }
    return NULL;
}

bool CommandLineReader::hasOptionUp(OPTIONS option)
{
    switch (option)
    {
        case ALL:
            return this->affichage && this->analyse && this->optimisation && this->execution;
        break;

        case AFFICHAGE:
            return this->affichage;
        break;

        case ANALYSE:
            return this->analyse;
        break;

        case OPTIMISATION:
            return this->optimisation;
        break;

        case EXECUTION:
            return this->execution;
        break;

        default:
            cout << "# Error : option inconnue demandée." << endl;
            return false;
        break;
    }
    return false;
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
    cout << "# Programme lancé en mode " << modeStr << endl;
}

/**
 * Private methods
 */
bool CommandLineReader::syntaxe_id (const string& id)
{
    boost::regex re("(?!(^var$|^const$|^ecrire$|^lire$))^[a-zA-Z][a-zA-Z0-9]*$");
    boost::cmatch matches;
    return boost::regex_match(id.c_str(), matches, re);
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