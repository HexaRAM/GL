#include "semantique.h"
#include "../symbole/ecriture.h"
#include "../symbole/lecture.h"
#include "../symbole/affectation.h"
#include "../symbole/declaration/declarationVar.h"
#include "../symbole/declaration/declarationConst.h"
#include "../symbole/declaration/num.h"
#include "../symbole/declaration/identificateur.h"
#include "../config.h"


#include <vector>
#include <iostream>
using namespace std;

Semantique::~Semantique()
{
    
}


/**
 * Analyse sémantique
 * Pseudo algorithme :
 * Avec `programme`, faire l'analyse sémantique !
 *      -> Faire toutes les déclarations (utiliser les méthodes déjà codées)
 *      -> Faire toutes les instructions :
 *              ** read : s'assurer que la variable a bien été déclarée
 *              ** write : s'assurer que l'expression a bien été déclarée (& instanciée dans le cas d'une variable)
 *              ** opération = : s'assurer que le membre de gauche est bien une variable DECLAREE / s'assurer que tous les membres de droites sont soit des constantes, soit des variables déclarées et instanciées !!
 */
bool Semantique::execute(Memory& mem)
{
    #ifdef DEBUG
        cout << "------------------------------" << endl;

        cout << "\t###\tDébut de l'analyse sémantique (option -a)\t###" << endl;
    #endif

    vector<Declaration*> liste_declaration = mem.getDeclarations();
    vector<Instruction*> liste_instruction = mem.getInstructions();

    #ifdef DEBUG
        cout << "Parcours des déclarations (" << liste_declaration.size() << ") !" << endl;
    #endif


    // on parcourt toutes les déclarations
    for (auto const& it : liste_declaration)
    {
        DeclarationVar* declaVar = dynamic_cast<DeclarationVar*> (it);
        DeclarationConst* declaConst = dynamic_cast<DeclarationConst*> (it);

        if (declaVar != NULL)
        {
            // c'est une déclaration de variable(s)
            vector<Identificateur*> idents = declaVar->getIdents();

            for (auto const& itvar : idents)
            {
                string ident = *itvar;
                bool ok = mem.addVariable(itvar);
                if (!ok)
                {   
                    #ifdef DEBUG
                        cout << "# La variable " << ident << " a déjà été déclarée." << endl;
                    #endif
                    return false;
                }
            }

        }
        else if (declaConst != NULL)
        {
            // c'est une déclaration de constante(s)
            vector<constante> consts = declaConst->getConstantes();

            for (auto const& itconst : consts)
            {
                string ident = *(itconst.ident);
                int value = *(itconst.value);
                bool ok = mem.addConstante(ident, value);
                if (!ok)
                {
                    #ifdef DEBUG
                        cout << "# La constante " << ident << " (value=" << value << ") a déjà été déclarée." << endl;
                    #endif
                    return false;
                }
            }
        }
        else
        {
            // ???
        }
    }

    #ifdef DEBUG
        mem.displayMemory();

        cout << "------------------------------" << endl;

        cout << "Parcours des instructions (" << liste_instruction.size() << ") !" << endl;
    #endif

    // on parcourt toutes les instructions
    for (auto const& it : liste_instruction)
    {
        Affectation* affectation = dynamic_cast<Affectation*> (it);
        Lecture* lecture = dynamic_cast<Lecture*> (it);
        Ecriture* ecriture = dynamic_cast<Ecriture*> (it);

        // expression -> faire une fonction récursive (ou itérative, osef) pour récupérer tous les identificateurs d'une expression !

        if (affectation != NULL)
        {
            // c'est une affectation

            // get expression -> récupérer tous les identificateurs (get idents) de l'expression et checker s'ils existent (déclarées) et si pour les variables ils ont bien été instanciés
            Expression* expr = affectation->getExpression();
            set<Identificateur*> idents = expr->getIdents();

            // #ifdef DEBUG
            //     cout << "Les identificateurs de l'affectation `" << *affectation << "` sont (taille=" << idents.size() << ") : ";
            //     for (auto const& ident : idents)
            //     {
            //         cout << *ident << " ";
            //     }
            //     cout << endl;
            // #endif

            for (auto const& ident : idents)
            {
                string name = (string)*ident;

                if (mem.isVariable(name))
                {
                    // référence une variable
                    if (!mem.isVariableSemanticInstanciated(name))
                    {
                        // variable non instanciée (voire non déclarée)
                        #ifdef DEBUG
                            cout << "# La variable `" << name << "` au sein de l'expression `" << *expr << "` n'a pas été instanciée." << endl;
                        #endif
                        return false;
                    }
                }
                else
                {
                    // référence autre chose : une constante ou rien du tout
                    if (!mem.isIdentificateurDeclared(name))
                    {
                        #ifdef DEBUG
                            cout << "# L'identificateur `" << name << "` au sein de l'expression `" << *expr << "` n'a pas été déclarée." << endl;
                        #endif
                        return false;
                    }
                }
            }

            // Si on a survécu jusqu'ici, c'est que l'expression est correcte sémantiquement

            // get identificateur -> checker que c'est bien une variable et qu'elle a été déclarée
            Identificateur* id = affectation->getIdentificateur();
            string name = (string)(*id);

            if (!mem.isVariableDeclared(name))
            {
                #ifdef DEBUG
                    cout << "# La partie gauche `" << name << "` au sein de l'instruction `" << *affectation << "` n'a pas été déclarée comme variable." << endl;
                #endif
                return false;
            }

            // on n'attribue pas la valeur à l'expression, par contre on check le bool comme quoi elle a été affectée
            mem.semanticInstanciation(name);

        }
        else if (lecture != NULL)
        {
            // c'est une lecture

            // get identificateur -> checker que c'est bien une variable et qu'elle a été déclarée

            Identificateur* id = lecture->getIdentificateur();
            string name = (string)(*id);

            // #ifdef DEBUG
            //     cout << "L'identificateur associé à la lecture est : " << *id << endl;
            // #endif

            if (!mem.isVariableDeclared(name))
            {
                #ifdef DEBUG
                    cout << "# Le paramètre `" << name << "` au sein de l'instruction `" << *lecture << "` n'a pas été déclaré comme variable." << endl;
                #endif
                return false;
            }

        }
        else if (ecriture != NULL)
        {
            // c'est une écriture

            // get expression -> récupérer tous les identificateurs de l'expression et checker s'ils existent et si pour les variables ils ont bien été instanciés
            Expression* expr = ecriture->getExpression();
            set<Identificateur*> idents = expr->getIdents();

            // #ifdef DEBUG
            //     cout << "Les identificateurs de l'écriture `" << *ecriture << "` sont (taille=" << idents.size() << ") : ";
            //     for (auto const& ident : idents)
            //     {
            //         cout << *ident << " ";
            //     }
            //     cout << endl;
            // #endif

            for (auto const& ident : idents)
            {

                string name = (string)*ident;

                if (mem.isVariable(name))
                {
                    // référence une variable
                    if (!mem.isVariableSemanticInstanciated(name))
                    {
                        // variable non instanciée (voire non déclarée)
                        #ifdef DEBUG
                            cout << "# La variable `" << name << "` n'a pas été instanciée." << endl;
                        #endif
                        return false;
                    }
                }
                else
                {
                    // référence autre chose : une constante ou rien du tout
                    if (!mem.isIdentificateurDeclared(name))
                    {
                        #ifdef DEBUG
                            cout << "# L'identificateur `" << name << "` au sein de l'expression `" << *expr << "` n'a pas été déclarée." << endl;
                        #endif
                        return false;
                    }
                }
            }
        }
        else
        {
            // ???
        }
    }

    return true;
}
