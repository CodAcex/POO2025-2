#ifndef MAGOBRANCO_H
#define MAGOBRANCO_H

#include "Mago.h"
using namespace std;

class MagoBranco: public Mago{
    public:
        MagoBranco(string nome, int idade, string escolaDeMagia);
        void LancarCura();

    protected:
        int poderCura;
};
#endif