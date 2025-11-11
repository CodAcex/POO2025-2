#ifndef FORMA_GEOMETRICA_H
#define FORMA_GEOMETRICA_H

#include <iostream>
#include <string>

using namespace std;

class FormaGeometrica{

    public:
        FormaGeometrica(string nome);
        ~FormaGeometrica();
        virtual void calcularArea() = 0;
        virtual void calcularPerimetro() = 0;

    protected:
        string nome;    
};

#endif