#ifndef CIRCULO_H
#define CIRCULO_H

#include "FormaGeometrica.h"

class Circulo : public FormaGeometrica{
    public:
    Circulo(float Raio);
    ~Circulo();
    virtual void calcularArea();
    virtual void calcularPerimetro();
    void calculoCirculo();

    protected:
    float Raio;
    float Pi = 3.14;
    float Area;
    float Perimetro;
};

#endif