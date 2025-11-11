#ifndef RETANGULO_H
#define RETANGULO_H

#include "FormaGeometrica.h"

class Retangulo : public FormaGeometrica{
    public:
    Retangulo(float Base, float Altura);
    ~Retangulo();
    virtual void calcularArea();
    virtual void calcularPerimetro();
    void calculoRetangulo();

    protected:
    float Base;
    float Altura;
    float Area;
    float Perimetro;
};

#endif