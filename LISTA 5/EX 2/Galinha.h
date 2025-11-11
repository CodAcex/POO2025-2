#ifndef GALINHA_H
#define GALINHA_H

#include "Animal.h"

class Galinha : public Animal{
    
    public:
        Galinha(string nome, string Som_Bicho);
        virtual void fazerSom();

    protected:
};

#endif