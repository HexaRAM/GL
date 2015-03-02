#if !defined ( AUTOMATE_H )
#define AUTOMATE_H

#include "../config.h"
#include <string>
using namespace std;

class Automate
{
    public:
        Automate();
        Automate(bool aff, bool ana, bool opti, bool exec, string code);
        virtual ~Automate() {}
        void lecture();
        void execute(OPTIONS option = ALL);

    private:
        bool affichage;
        bool analyse;
        bool optimisation;
        bool execution;

        string code;

        void executeAll();
        void executeAffichage();
        void executeAnalyse();
        void executeOptimisation();
        void executeExecution();

};
#endif