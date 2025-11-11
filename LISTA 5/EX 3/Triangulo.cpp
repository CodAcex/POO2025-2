#include "Triangulo.h"

Triangulo::Triangulo(float Base, float Altura, float Lado1, float Lado2, float Lado3) : FormaGeometrica("Triangulo"), Base(0), Altura(0), Lado1(0), Lado2(0), Lado3(0)
{
    this->Base = Base;
    this->Altura = Altura;
    this->Lado1 = Lado1;
    this->Lado2 = Lado2;
    this->Lado3 = Lado3;
    cout << "Triangulo Criado" << endl;
}

Triangulo::~Triangulo()
{
}

void Triangulo::calcularArea()
{
    Area = (Base * Altura) / 2;
    cout << "A area do triangulo é: " << Area << endl;
}

void Triangulo::calcularPerimetro()
{
    Perimetro = Lado1 + Lado2 + Lado3;
    cout << "O perimetro do triangulo é: " << Perimetro << endl;
}

void Triangulo::calculoTriangulo()
{
    cout << "Insira a Base do Triangulo: ";
    cin >> Base;
    cout << "Insira a Altura do Triangulo: ";
    cin >> Altura;
    cout << "Insira o lado 1 do Triangulo: ";
    cin >> Lado1;
    cout << "Insira o lado 2 do Triangulo: ";
    cin >> Lado2;
    cout << "Insira o lado 3 do Triangulo: ";
    cin >> Lado3;
}
