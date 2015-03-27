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

    for(auto const &it:liste_instruction){
       Affectation *aff = dynamic_cast<Affectation*> (it);
       Lecture *lec = dynamic_cast<Lecture*> (it);
       Ecriture *ecr = dynamic_cast<Ecriture*> (it);
       if(aff != NULL){
            cout<<"Affectation ";
            cout<<"exp = " << *(aff->getExpression());
            cout<<" id = " << *(aff->getIdentificateur());
            cout<<endl;

       }else if(lec != NULL){
            cout<<"Lecture ";
            cout<<"id = " << *(lec->getIdentificateur());
            cout<<endl;
       }else if(ecr != NULL){
            cout<<"Ecriture ";
            cout<<"exp = " << *(ecr->getExpression());
            cout<<endl;
       }
    }

    cout<<"Nombre d'instructions = "<< liste_instruction.size() << endl;
    return true;
}