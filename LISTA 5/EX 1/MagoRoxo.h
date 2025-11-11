#ifndef MAGOROXO_H
#define MAGOROXO_H

#include "Mago.h"

class MagoRoxo: public Mago
{
    public:
    MagoRoxo(string nome, int idade, string escolaDeMagia);
    void CriarIlusao();

    protected:
    int Ilusao;
};
#endif