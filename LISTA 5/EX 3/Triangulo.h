#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "FormaGeometrica.h"

class Triangulo : public FormaGeometrica{
    public:
    Triangulo(float Base, float Altura, float Lado1, float Lado2, float Lado3);
    ~Triangulo();
    virtual void calcularArea();
    virtual void calcularPerimetro();
    void calculoTriangulo();

    protected:
    float Base;
    float Altura;
    float Lado1, Lado2, Lado3;
    float Area;
    float Perimetro;
};

#endif

