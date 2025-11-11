#include "Retangulo.h"

Retangulo::Retangulo(float Base, float Altura) : FormaGeometrica("Retangulo"), Base(0), Altura(0)
{
    cout << "Reatangulo Criado com sucesso " << endl;
    this->Base = Base;
    this->Altura = Altura;
    this->Area = Area;
    this->Perimetro = Perimetro;
}

Retangulo::~Retangulo()
{
}

void Retangulo::calcularArea()
{
   Area = Base * Altura;
   cout << "A Area do retangulo é: "<< Area << endl;
}

void Retangulo::calcularPerimetro() 
{
    Perimetro = (Base + Altura) * 2;
    cout << "O perimetro do retangulo é: "<< Perimetro << endl;
}

void Retangulo::calculoRetangulo()
{
    cout << "Insira a Base do Retangulo: ";
    cin >> Base;
    cout << "Insira a Altura: ";
    cin >> Altura;
}
