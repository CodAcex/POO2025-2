#include "Galinha.h"

Galinha::Galinha(string nome, string Som_Bicho) : Animal(nome, Som_Bicho)
{
    cout << "Galinha " << nome << " Foi criado" << endl;
    cout << Som_Bicho << endl;
}

void Galinha::fazerSom()
{
    cout << "CO CORICO" << endl;
}
