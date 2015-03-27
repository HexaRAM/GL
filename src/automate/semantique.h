#if !defined ( SEMANTIQUE_H )
#define SEMANTIQUE_H

#include "action.h"
#include "../symbole/expr/expression.h"

class Semantique : public Action
{
    public:
        Semantique() : Action() {}
        ~Semantique();
        bool execute(Memory& mem);

    private:
        bool checkExpression(Memory& mem, Expression* e);
};

#endif