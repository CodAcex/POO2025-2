#ifndef MAGOVERDE_H
#define MAGOVERDE_H

#include "Mago.h"

class MagoVerde: public Mago
{
    public:
    MagoVerde(string nome, int idade, string escolaDeMagia);
    void FalarComAnimais();

    protected:
    string falarCachorro;
};
#endif