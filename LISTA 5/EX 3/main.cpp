#include "Retangulo.h"
#include "Circulo.h"
#include "Triangulo.h"

int main()
{
    Retangulo retangulo(0,0);
    retangulo.calculoRetangulo();
    retangulo.calcularArea();
    retangulo.calcularPerimetro();

    Circulo circulo(0);
    circulo.calculoCirculo();
    circulo.calcularArea();
    circulo.calcularPerimetro();

    Triangulo triangulo(0,0,0,0,0);
    triangulo.calculoTriangulo();
    triangulo.calcularArea();
    triangulo.calcularPerimetro();

    return 0;
}

