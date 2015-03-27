#ifndef H_COMMAND_LINE_READER
#define H_COMMAND_LINE_READER

#include <string>
#include "config.h"
#include "automate/automate.h"
using namespace std;

class CommandLineReader
{
    public:
        CommandLineReader(int, char**);
        virtual ~CommandLineReader();
        void displayMode();
        Automate* createAutomate();

    private:
        bool enableCreationOfAutomate;
        bool affichage;
        bool analyse;
        bool optimisation;
        bool execution;
        string nomFichier;

        bool syntaxe_filename (const string& filename);
        bool syntaxe_options (const string& option);

        void usage(); // affiche les usages du programme
};

#endif