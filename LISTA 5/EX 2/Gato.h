#ifndef GATO_H
#define GATO_H

#include "Animal.h"

class Gato : public Animal{
    
    public:
        Gato(string nome, string Som_Bicho);
        virtual void fazerSom();

    protected:
};

#endif