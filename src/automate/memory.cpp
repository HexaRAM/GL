#include "memory.h"
#include "../config.h"

#include <iostream>
using namespace std;

Memory::~Memory()
{
    delete programme;
}

/**
 * Ajouter une variable à la map des variables
 * Si l'identificateur a déjà été utilisé, renvoie false avec un message d'erreur
 */
bool Memory::addVariable(Identificateur* const id)
{
    string name = (string)(*id);

    if (this->idents.find(name) != this->idents.end())
    {
        // var already exists
        cerr << "# L'identificateur `" << name << "` a déjà été utilisé par une autre variable/constante." << endl;
        return false;
    }

    // var doesn't exist
    this->variables[name] = {-1, false, false};
    this->idents.insert(name);
    return true;
}


/**
 * Ajouter une constante à la map des constantes
 * Si l'identificateur a déjà été utilisé, renvoie false avec un message d'erreur
 */
bool Memory::addConstante(const string& name, int value)
{
    if (this->idents.find(name) != this->idents.end())
    {
        // const already exists
        cerr << "# L'identificateur `" << name << "` (" << value << ") a déjà été utilisé par une autre variable/constante." << endl;
        return false;
    }

    // const doesn't exist
    this->constantes[name] = {value};
    this->idents.insert(name);
    return true;
}

/**
 * Instancier une variable dans la mémoire sans valeur
 * Si la variable n'existe pas, renvoie false avec un message d'erreur
 */
void Memory::semanticInstanciation(const string& name)
{
    if (this->idents.find(name) == this->idents.end())
    {
        // idents `name` doesn't exist
        cerr << "# La variable " << name << " n'existe pas." << endl;
        return;
    }

    map_var::iterator it = variables.find(name);

    if (it == variables.end())
    {
        // var doesn't exist
        cerr << "# La variable " << name << " n'existe pas." << endl;
        return;
    }

    // var exist
    it->second.isSemanticInstanciated = true;
}

/**
 * Instancier une variable dans la mémoire avec une valeur
 * Si la variable n'existe pas, renvoie false avec un message d'erreur
 */
bool Memory::instanciateVariable(const string& name, int value)
{

    #ifdef DEBUG
        cout << "On affecte " << value << " à la variable " << name << endl;
    #endif

    if (this->idents.find(name) == this->idents.end())
    {
        // idents `name` doesn't exist
        cerr << "# La variable " << name << " n'existe pas. Veuillez la créer avant de vouloir lui affecter une valeur." << endl;
        return false;
    }

    map_var::iterator it = variables.find(name);

    if (it == variables.end())
    {
        // var doesn't exist
        cerr << "# La variable " << name << " n'existe pas. Veuillez la créer avant de vouloir lui affecter une valeur." << endl;
        return false;
    }

    // var exist
    it->second.instanciated = true;
    it->second.value = value;
    return true;
}

/**
 * Tester si une variable a déjà été lue (pour l'analyseur statique)
 * Si la variable n'existe pas en tant que variable, renvoie false avec un message d'erreur
 */
bool Memory::isVariableSemanticInstanciated(const string& name)
{
    map_var::iterator it = this->variables.find(name);

    if (it == this->variables.end())
    {
        // variable `name` doesn't exist
        cerr << "# La variable " << name << " n'existe pas." << endl;
        return false;
    }

    return it->second.isSemanticInstanciated;
}

/**
 * Tester si une variable a été déclarée
 * Si la variable n'existe pas en tant que variable, renvoie false
 */
bool Memory::isVariableDeclared(const string& name)
{
    if (this->variables.find(name) != this->variables.end())
    {
        return true;
    }
    return false;
}

/**
 * Tester si un identificateur a été déclarée
 * Si l'identificateur n'existe pas, renvoie false
 */
bool Memory::isIdentificateurDeclared(const string& name)
{
    if (this->idents.find(name) != this->idents.end())
    {
        return true;
    }
    return false;
}

/**
 * Alias de la méthode isVariableDeclared
 */
bool Memory::isVariable(const string& name)
{
    return this->isVariableDeclared(name);
}

/**
 * Afficher l'état de la mémoire sur la sortie standard
 */
 void Memory::displayMemory()
{
    #ifdef DEBUG
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
            cout << ")";

            if (it.second.isSemanticInstanciated)
            {
                cout << " but semantic instanciated !";
            }
            cout << endl;
        }
    #endif

    cout << *programme;
}

map<string, double> Memory::buildEvalMap()
{
    map<string, double> map_val;
    
    for (auto it : variables)
    {
        map_val[it.first] = it.second.value;
    }
    
    for (auto it : constantes)
    {
        map_val[it.first] = it.second.value;
    }
    
    return map_val;
}

map<string, double> Memory::getMapConst()
{

    map<string, double> map_val;

    for (auto it : constantes)
    {
        map_val[it.first] = it.second.value;
    }
    return map_val;
}
