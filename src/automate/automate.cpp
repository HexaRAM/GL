#include "automate.h"
#include <iostream>
#include <boost/regex.hpp>
using namespace std;


Automate::Automate()
{
    // init
    this->affichage = false;
    this->analyse = false;
    this->optimisation = false;
    this->execution = false;
    this->code = "";
    this->buffer = "";
    this->lexer = Lexer();
}

Automate::Automate(bool affichage, bool analyse, bool optimisation, bool execution, string code)
{
    this->affichage = affichage;
    this->analyse = analyse;
    this->optimisation = optimisation;
    this->execution = execution;
    this->code = code;
    this->buffer = code;
    this->lexer = Lexer();
}

/**
 * Public methods
 */
bool Automate::addVariable(const string& name)
{
    if (this->idents.find(name) != this->idents.end())
    {
        // var already exists
        cout << "# L'identificateur `" << name << "` a déjà été utilisé par une autre variable/constante." << endl;
        return false;
    }
    else
    {
        // var doesn't exist
        this->variables[name] = {0, false};
        this->idents.insert(name);
        cout.flush();
        return true;
    }
}

bool Automate::addConstante(const string& name, int value)
{
    if (this->idents.find(name) != this->idents.end())
    {
        // const already exists
        cout << "# L'identificateur `" << name << "` (" << value << ") a déjà été utilisé par une autre variable/constante." << endl;
        return false;
    }

    // const doesn't exist
    this->constantes[name] = {value};
    this->idents.insert(name);
    return true;
}

bool Automate::instanciateVariable(const string& name, int value)
{

    if (this->idents.find(name) == this->idents.end())
    {
        // idents `name` doesn't exist
        cout << "# La variable " << name << " n'existe pas. Veuillez la créer avant de vouloir lui affecter une valeur." << endl;
        return false;
    }

    map_var::iterator it = variables.find(name);

    if (it == variables.end())
    {
        // var doesn't exist
        cout << "# La variable " << name << " n'existe pas. Veuillez la créer avant de vouloir lui affecter une valeur." << endl;
        return false;
    }

    // var exist
    it->second.instanciated = true;
    it->second.value = value;
    return true;
}

void Automate::displayMemory()
{
    cout << "# Constantes :" << endl;
    for (auto const& it : this->constantes)
    {
        cout << "\tconst " << it.first << " = " << it.second.value << ";" << endl;
    }
    cout << endl << "# Variables : "<< endl;
    for (auto const &it : this->variables)
    {

        cout << "\tvar " << it.first << "; (";
        if (it.second.instanciated)
        {
            cout << "valeur : " << it.second.value;
        }
        else
        {
            cout << "non instanciée";
        }
        cout << ")" << endl;
    }
}

void Automate::execute(OPTIONS option)
{
    switch (option)
    {
        case ALL:
            executeAll();
        break;

        case AFFICHAGE:
            executeAffichage();
        break;

        case ANALYSE:
            executeAnalyse();
        break;

        case OPTIMISATION:
            executeOptimisation();
        break;

        case EXECUTION:
            executeExecution();
        break;

        default:
            cout << "# Error : option inconnue demandée." << endl;
        break;
    }
}


/**
 * Private & Debug methods
 * Maybe (surely) it's impossible to launch all of them separately
 */
void Automate::executeAll()
{
    executeAffichage();
    executeAnalyse();
    executeOptimisation();
    executeExecution();
}

void Automate::executeAffichage()
{
    if (!this->affichage)
    {
        cout << "# Warning : l'affichage n'a pas été demandé par l'utilisateur." << endl;
    }

    cout << code << endl;

    // TODO
}

void Automate::executeAnalyse()
{
    if (!this->analyse)
    {
        cout << "# Warning : l'analyse n'a pas été demandé par l'utilisateur." << endl;
    }

    // TODO
}

void Automate::executeOptimisation()
{
    if (!this->optimisation)
    {
        cout << "# Warning : l'optimisation n'a pas été demandé par l'utilisateur." << endl;
    }

    // TODO
}

void Automate::executeExecution()
{
    if (!this->execution)
    {
        cout << "# Warning : l'exécution n'a pas été demandé par l'utilisateur." << endl;
    }

    // TODO
}

string Automate::getNext()
{
    return this->lexer.getNext(this->buffer);
}

void Automate::displayBuffer()
{
    cout << this->buffer << endl;
}

// LEXER
// char** Lexer::regex = {"", "", "", ""};

Lexer::Lexer()
{

}

Lexer::~Lexer()
{

}

string Lexer::regex[] = {"^const$", "^var$", "^lire$", "^ecrire$", ";", "\\(", "\\)", ":=", "=", "\\+", "\\-", "\\*", "\\/", "\\,", "^\\d$","(?!(^var$|^const$|^ecrire$|^lire$))^[a-zA-Z][a-zA-Z0-9]*$"};

string Lexer::getNext(string& buff)
{
    if (buff.empty())
    {
        return ""; // DOLLAR / EOF
    }

    stringstream flux(buff);
    string buffer = "";
    bool stop = false;
    int id = -1;

    while (!flux.fail())
    {
        char charactere = (char)flux.peek();
        bool matched = false;
        cout << "BUFFER : " << buffer << endl;

        switch (charactere)
        {
            // caractères d'arrêt
            case ';':
            case ' ':
            case '+':
            case '-':
            case '/':
            case '*':
            case ',':
            case '=':
                stop = true;
            break;

            default:
                buffer += charactere;
            break;
        }

        /**
         * TODO : changer ça parce que c'est vraiment pas propre !!!!
         */

        if (stop)
        {
            bool got = false;

            if (charactere == ' ')
            {
                flux.get();
                got = true;
            }

            if (!got && buffer.empty())
            {
                buffer += charactere;
                flux.get();
            }

            break;
        }
        
        flux.get(); // eat charactere

        for (unsigned int i = 0; i < NB_REGEX; ++i)
        {
            boost::regex re(Lexer::regex[i].c_str());
            boost::cmatch matches;
            bool match = boost::regex_match(buffer.c_str(), matches, re);
            if (match)
            {
                id = i;
                matched = true;
                break;
            }
        }

        if (!matched)
        {
            break;
        }
    }

    // renvoyer le symbole qui match en fonction du buffer
    getline(flux, buff);
    return buffer;
}