#include "lexer.h"
#include "../config.h"

#include "../symbole/symbole.h"
#include "../symbole/declaration/num.h"
#include "../symbole/declaration/identificateur.h"
#include "../symbole/unknown.h"
#include <boost/regex.hpp>

Lexer::Lexer()
{
    this->charRead = 0;
}

Lexer::Lexer(vector<int> linesBreaks)
{
    this->line = 1;
    this->column = 1;
    this->linesBreaks = linesBreaks;
    this->charRead = 0;
}

Lexer::~Lexer()
{
    // rien à détruire
}

string Lexer::regex[] = {"^const$", "^var$", "^lire$", "^ecrire$", ";", "\\(", "\\)", ":=", "=", "\\+", "\\-", "\\*", "\\/", "\\,", "^\\d*$","(?!(^var$|^const$|^ecrire$|^lire$))^[a-zA-Z][a-zA-Z0-9]*$"};

/**
 * /!\ Implémentation légèrement différente de l'algo décrit ci-dessous avec l'intégration du ":=" qui a nécessité d'ajouter un compteur "no_pattern_sequence" pour tolérer le fait qu'on ne rencontre aucun pattern par moment (e.g quand on reçoit ":")
 * TODO :
 *      - si caractère arrêt
 *          * si tout seul dans le buffer [buffer vide] (buffer == caractère arrêt)
 *              -> si pas espace => flux.get() && retourner le symbole
 *              -> si espace => flux.get() et continuer
 *          * si pas tout seul dans le buffer (c'est le symbole d'encore après, [opti : on pourrait le save])
 *              -> si carac_arret == espace => flux.get() et retour du buffer
 *              -> si carac_arret == pas espace => retour du buffer
 *      - si pas caractère arrêt => ajouter caractère au buffer [new_buff]
 *          * tester new_buff sur chaque regex
 *              -> si match => flux.get() mettre un flag à match et continue
 *              -> si non match
                    ** si flag à match => retourner buffer (/!\ pas new_buff)
 *                  ** si flag à non match => retourner erreur (aucun pattern trouvé)
 *
 */
Symbole* Lexer::getNext(string& buff)
{
    // on récupère les core informations
    this->getCurrentLineAndColumn(line, column);

    if (buff.empty())
    {
        return new Symbole(ID_SYMBOLE::dollar); // symbole DOLLAR / EOF
    }

    stringstream flux(buff);
    string buffer = "";
    bool match_flag = false;
    bool error = false;
    bool last_was_no_pattern = false;
    int no_pattern_sequence = 0;
    int id = -1;

    while (!flux.fail())
    {
        char character = (char)flux.peek(); // prochain caractère
        bool stoping_char = false;
        //cout << "BUFFER : " << buffer << " (next character : " << character << ") / no pattern sequence : " << no_pattern_sequence << " !" << endl; // état du buffer

        // TODO : gérer le :=

        // caractère arrêt ?
        switch (character)
        {
            case ' ':
            case ';':
            case '+':
            case '-':
            case '/':
            case '*':
            case ',':
            case '(':
            case ')':
                stoping_char = true;
            break;

            default:

            break;
        }

        if (stoping_char)
        {
            // * si tout seul dans le buffer [buffer vide] (buffer == caractère arrêt)
            if (buffer.empty())
            {
                flux.get();
                charRead++;
                // -> si espace
                if (character == ' ')
                {
                    this->getCurrentLineAndColumn(line, column);
                    continue;
                }
                // -> sinon
                buffer = character;
                break; // return buffer;
            }

            // * sinon
            // -> si espace
            if (character == ' ')
            {
                flux.get();
                charRead++;
            }
            // -> sinon
            break; // return buffer;
        }

        // - si pas caractère arrêt
        string new_buff = buffer + character;

        // test des regex
        bool matched = false;
        for (unsigned int i = 0; i < NB_REGEX; ++i)
        {
            boost::regex re(Lexer::regex[i].c_str());
            boost::cmatch matches;
            bool match = boost::regex_match(new_buff.c_str(), matches, re);
            if (match)
            {
        id = i;
                matched = true;
                break;
            }
        }

        //cout << "NEW BUFF : " << new_buff << " / matched ? " << ((matched) ? "yes" : "no") << endl;
        if (matched)
        {
            flux.get();
            charRead++;
            match_flag = true;
            buffer = new_buff;
            last_was_no_pattern = false;
            continue;
        }
        else
        {
            if (match_flag)
            {
                break; // return buffer;
            }

            // Aucun pattern trouvé, on continue pour voir si un pattern va apparaître
            if (last_was_no_pattern)
            {
                no_pattern_sequence++;
            }
            else
            {
                last_was_no_pattern = true;
                no_pattern_sequence = 1;
            }
 
            if (no_pattern_sequence >= MAX_NO_PATTERN_SEQUENCE)
            {
                error = true;
                break;
            }

            buffer = new_buff;
            flux.get();
            charRead++;
        }
    } // fin du while

    // mise à jour du buffer dans l'automate
    getline(flux, buff);

    if (error)
    {
        #ifdef DEBUG
            cout << "Erreur - aucun pattern trouvé dans les " + std::to_string(MAX_NO_PATTERN_SEQUENCE) + " derniers caractères." << endl;
        #endif
       return NULL;
    }

    Symbole* retour = NULL;

    //cout << "Valeur du symbole lu : " << buffer << "(ID : " << id << ")" << endl;

    switch(id)
    {
        case -1:
            if (buffer == ";")
            {
                retour = new Symbole(ID_SYMBOLE::pv);
            }
            else if (buffer == "+")
            {
                retour = new Symbole(ID_SYMBOLE::add); 
            }
            else if (buffer == "-")
            {
                retour = new Symbole(ID_SYMBOLE::moins);
            }
            else if (buffer == "/")
            {
                retour = new Symbole(ID_SYMBOLE::divise);
            }
            else if (buffer == "*")
            {
                retour = new Symbole(ID_SYMBOLE::fois);
            }
            else if (buffer == ",")
            {
                retour = new Symbole(ID_SYMBOLE::v);
            }
            else if (buffer == "(")
            {
                retour = new Symbole(ID_SYMBOLE::po);
            }
            else if (buffer == ")")
            {
                retour = new Symbole(ID_SYMBOLE::pf);
            }
            else
            {
                // error
                if (buffer.size() > 0)
                {
                    retour = new Unknown(buffer.at(0));
                    cerr << "Erreur lexicale (" << line << ":" << column << ") caractere " << buffer.at(0) << endl;
                    // on ignore le caractère
                    delete retour;
                    retour = getNext(buff);
                }
                else
                {
                    // error, on ignore le caractère
                    #ifdef DEBUG
                        cout << "Erreur : le buffer est vide et on est sorti de la boucle de lecture ..." << endl;
                    #endif
                    retour = getNext(buff);
                }
            }
        break;
        case 0:
            retour = new Symbole(ID_SYMBOLE::ct);
        break;
        case 1:
            retour = new Symbole(ID_SYMBOLE::va);
        break;
        case 2:
            retour = new Symbole(ID_SYMBOLE::r);
        break;
        case 3:
            retour = new Symbole(ID_SYMBOLE::w);
        break;
        case 4:
            retour = new Symbole(ID_SYMBOLE::pv);
        break;
        case 5:
            retour = new Symbole(ID_SYMBOLE::po);
        break;
        case 6:
            retour = new Symbole(ID_SYMBOLE::pf);
        break;
        case 7:
            retour = new Symbole(ID_SYMBOLE::af);
        break;
        case 8:
            retour = new Symbole(ID_SYMBOLE::eg);
        break;
        case 9:
            retour = new Symbole(ID_SYMBOLE::add);
        break;
        case 10:
            retour = new Symbole(ID_SYMBOLE::moins);
        break;
        case 11:
            retour = new Symbole(ID_SYMBOLE::fois);
        break;
        case 12:
            retour = new Symbole(ID_SYMBOLE::divise);
        break;
        case 13:
            retour = new Symbole(ID_SYMBOLE::v);
        break;
        case 14:
        {
            // convertir buffer -> int
            int num;
            istringstream iss(buffer);
            iss >> num;
            retour = new Num(num);
        }
        break;
        case 15:
        {
            retour = new Identificateur(buffer);
        }
        break;
        default:
            // error
            if (buffer.size() > 0)
            {
                retour = new Unknown(buffer.at(0));
                cerr << "Erreur lexicale (" << line << ":" << column << ") caractere " << buffer.at(0) << endl;
                // on ignore le caractère
                delete retour;
                retour = getNext(buff);
            }
            else
            {
                // error, on ignore le caractère
                #ifdef DEBUG
                    cout << "Erreur : le buffer est vide et on est sorti de la boucle de lecture ..." << endl;
                #endif
                retour = getNext(buff);
            }
        break;
    }

    //cout << " --> Lecture d'un symbole : " << *retour << endl;
    return retour;
}

void Lexer::getCurrentLineAndColumn(int& line, int& column)
{
    // charRead --> nombre de caractères lues
    // linesBreaks --> nombre de caractères par ligne

    int charFile = 0;
    line = 1;
    column = 1;

    // 9 12 11 6 15 7 11 7 9 0

    for (auto const& it : linesBreaks)
    {
        charFile += it;
        if (charRead < charFile)
        {
            // on est dans la bonne ligne
            // on récupère la colonne :
            // it --> nombre de caractères sur la ligne
            // charFile-charRead-1 --> nombre de caractères à droite du caractère que l'on souhaite cibler
            column = it-(charFile-charRead-1);
            break;
        }
        line++;
    }
}