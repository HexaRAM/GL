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

    for (auto const &it : liste_instruction)
    {
        Affectation *aff = dynamic_cast<Affectation*> (it);
        Lecture *lec = dynamic_cast<Lecture*> (it);
        Ecriture *ecr = dynamic_cast<Ecriture*> (it);

        if(aff != NULL)
        {
            //Affectation

            double valExpr = (aff->getExpression())->eval(map_val);

            if(mem.instanciateVariable(*(aff->getIdentificateur()), (int)valExpr)) {

                map_val[*(aff->getIdentificateur())] = valExpr;

            }else{
                return false;
            }
                        

        }
        else if(lec != NULL)
        {
            //Lecture

            int val; 
            if (cin >> val) {
                   
                if(mem.instanciateVariable(*(lec->getIdentificateur()), val)) {
                    map_val[*(lec->getIdentificateur())] = val;            
                }else{
                return false;
                }
            }else{
                return false;
            }      
            
        }
        else if(ecr != NULL)
        {
            //Ecriture
            cout << ecr->getExpression()->eval(map_val) << endl;
       }
    }
    
    return true;
}