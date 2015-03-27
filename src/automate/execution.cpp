#include "execution.h"

#include "../symbole/ecriture.h"
#include "../symbole/lecture.h"
#include "../symbole/affectation.h"

#include <iostream>
using namespace std;

Execution::~Execution()
{

}

bool Execution::execute(Memory& mem)
{
    vector<Instruction*> liste_instruction = mem.getInstructions();

    // création d'une map associant les identifiants à leur valeur directement pour l'évaluation des expressions
    map<string, double> map_val = mem.buildEvalMap();

    //cout<<variables.size()<<endl;
    //cout<<constantes.size()<<endl;
    //cout<<map_val.size()<<endl;

    for (auto const &it : liste_instruction)
    {
        Affectation *aff = dynamic_cast<Affectation*> (it);
        Lecture *lec = dynamic_cast<Lecture*> (it);
        Ecriture *ecr = dynamic_cast<Ecriture*> (it);

        if(aff != NULL)
        {
            // c'est une affectation
            cout << "----------------------" << endl;
            //TODO addVariable()

            double valExpr = (aff->getExpression())->eval(map_val);

            map_val[*(aff->getIdentificateur())] = valExpr;
            cout << *aff << "AFF: La variable '" << *(aff->getIdentificateur()) <<"' a la valeur " << valExpr << endl;
            cout << "La taille de ma map: " << map_val.size() << endl;

        }
        else if(lec != NULL)
        {
            cout << "----------------------"  << endl;
            cout << *lec << "LEC: Je lis une valeur pour la variable '" <<  *(lec->getIdentificateur()) << "'" << endl;
            
            double val = 0; 
            cin >> val;

            cout << "J'ai lu " << *(lec->getIdentificateur()) << " = " <<val << endl;

            //Je rajoute dans ma map la nouvelle valeur de la var
            map_val[*(lec->getIdentificateur())] = val;
            cout << "La taille de ma map: " << map_val.size() << endl;
            //TODO addVariable()
            
        }
        else if(ecr != NULL)
        {
            cout << "----------------------" << endl;
            cout << *ecr << "J'ecris: " << ecr->getExpression()->eval(map_val) << endl;
       }
    }
    
    return true;
}