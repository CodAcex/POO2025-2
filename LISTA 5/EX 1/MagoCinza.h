#ifndef MAGOCINZA_H
#define MAGOCINZA_H

#include "Mago.h"

class MagoCinza: public Mago
{
    public:
    MagoCinza(string nome, int idade, string escolaDeMagia);
    void PrepararPocao();

    protected:
    int PocaoCura;
};
#endif