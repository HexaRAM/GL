#include "optimisation.h"
#include "../symbole/affectation.h"
#include "../symbole/ecriture.h"
#include "../symbole/declaration/num.h"

#include <iostream>
#include <string>
using namespace std;

Optimisation::~Optimisation()
{

}

bool Optimisation::execute(Memory& mem)
{	
	set<Identificateur*> identificateurs;

    // propagation des constantes
    // à chaque tour, il faut mettre à jour les maps pour l'optimisation
    // i.e une variable peut devenir une constante ! (quand isConst est ok dans une affectation, mettre à jour la map avec la nouvelle valeur calculée)

    map<string, double> value_map = mem.buildEvalMapConst();

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
				if (!this->isConst(j,value_map))
                {
					isConst = false;
					break;
				}			
    		}

            // on remplace toute l'expression par un NUM si l'expression est entièrement constante
    		if(isConst)
    		{
    			//tous les membres de l'affectation sont constants, il faut l'évaluer, et remplacer l'expression dedans
    			double value = (affectation->getExpression())->eval(value_map);
    			Num* newExpression = new Num((int)value);
                value_map[(string)*(affectation->getIdentificateur())] = value;
    			affectation->setExpression(newExpression);
    		}
            else
            {
                // sinon, on remplace les parties constantes de l'expression (qui ne sont pas des nums bien sûr)
                for (auto &j : identificateurs)
                {
                    if (this->isConst(j, value_map))
                    {
                        Num* num = dynamic_cast<Num*>(j);

                        if (num == NULL)
                        {
                            // c'est pas un num, on remplace
                            double value = j->eval(value_map);
                            delete j;

                            Num* addr = (Num*)&j; // on dit à j qu'il pointe maintenant un num -> addr contient l'adresse de j
                            addr = (Num*) new Num((int) value); // on met l'adresse du nouveau num dans j.
                        }
                    }
                }                   
            }			
    	}

    	else if(ecriture != NULL)
    	{
    		identificateurs = ecriture->getExpression()->getIdents();
    		bool isConst = true;
    		for (auto const &j : identificateurs)
    		{
				if (!this->isConst(j,value_map))
                {
					isConst = false;
					break;
				}			
    		}

    		if (isConst)
    		{
    			//l'ecriture est constante, il faut l'évaluer, et remplacer l'expression dedans
    			double value = (ecriture->getExpression())->eval(value_map);
    			Num* newExpression = new Num((int)value);
    			ecriture->setExpression(newExpression);
    		}
            else
            {
                // sinon, on remplace les parties constantes de l'expression (qui ne sont pas des nums bien sûr)
                for (auto &j : identificateurs)
                {
                    if (this->isConst(j, value_map))
                    {
                        Num* num = dynamic_cast<Num*>(j);

                        if (num == NULL)
                        {
                            // c'est pas un num, on remplace
                            double value = j->eval(value_map);
                            delete j;

                            Num* addr = (Num*)&j; // on dit à j qu'il pointe maintenant un num -> addr contient l'adresse de j
                            addr = (Num*) new Num((int) value); // on met l'adresse du nouveau num dans j.
                        }
                    }
                }
            }         			
    	}  		
  	}
    return true;
}

bool Optimisation::isConst(Identificateur* id, map<string, double>& value_map)
{
	for(auto const &it : value_map)
	{
    	if((string)(*id) == it.first)
        {
    	    return true;
        }
	}
	return false;
}

