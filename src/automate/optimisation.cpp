#include "optimisation.h"
#include "../symbole/affectation.h"
#include "../symbole/ecriture.h"
#include "../symbole/declaration/num.h"

Optimisation::~Optimisation()
{

}

bool Optimisation::execute(Memory& mem)
{	
	set<Identificateur*> identificateurs;
  	for (auto &it : mem.getInstructions())
  	{
  		set<Identificateur*> identificateurs;

  		Affectation *affectation = dynamic_cast<Affectation*> (it);
    	Ecriture *ecriture = dynamic_cast<Ecriture*> (it);

    	if(affectation != NULL)
    	{
    		identificateurs = affectation->getExpression()->getIdents();
    		bool isConst = true;
    		for(auto const &j : identificateurs)
    		{
				if(!this->isConst(j,mem)){
					isConst = false;
					break;
				}			
    		}
    		if(isConst)
    		{
    			//tous les membres de l'affectation sont constants, il faut l'évaluer, et remplacer l'expression dedans
    			double value = (affectation->getExpression())->eval(mem.getMapConst());
    			Num* newExpression = new Num((int)value);
    			affectation->setExpression(newExpression);
    		}    			
    	}

    	else if(ecriture != NULL)
    	{
    		identificateurs = ecriture->getExpression()->getIdents();
    		bool isConst = true;
    		for(auto const &j : identificateurs)
    		{
				if(!this->isConst(j,mem)){
					isConst = false;
					break;
				}			
    		}
    		if(isConst)
    		{
    			//l'ecriture est constante, il faut l'évaluer, et remplacer l'expression dedans
    			double value = (ecriture->getExpression())->eval(mem.getMapConst());
    			Num* newExpression = new Num((int)value);
    			ecriture->setExpression(newExpression);
    		}    			
    	}  		
  	}
    return true;
}

bool Optimisation::isConst(Identificateur* id, Memory& mem)
{
	for(auto const &it : mem.getMapConst())
	{
    	if((string)(*id) == it.first)
    	return true;
	}
	return false;
}

