#include "Circulo.h"

Circulo::Circulo(float Raio) : FormaGeometrica("Circulo"), Raio(0)
{
    this->Raio = Raio;
    this->Area = Area;
    this->Perimetro = Perimetro;
    cout << "Circulo Criado" << endl;
}

Circulo::~Circulo()
{
}

void Circulo::calcularArea()
{
    Area = Pi * (Raio * Raio);
    cout << "A Area do circulo é: "<< Area << endl;
}

void Circulo::calcularPerimetro()
{
    Perimetro = 2 * Pi * Raio;
    cout << "O perimetro do circulo é: "<< Perimetro << endl;
}

void Circulo::calculoCirculo()
{
    cout << "Insira o Raio do Circulo: ";
    cin >> Raio;
}
