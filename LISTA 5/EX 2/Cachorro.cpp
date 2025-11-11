#include "Cachorro.h"

Cachorro::Cachorro(string nome, string Som_Bicho) : Animal(nome, Som_Bicho)
{
    cout << "Cachorro " << nome << " foi criado" << endl;
    cout << Som_Bicho << endl;
}

void Cachorro::fazerSom()
{
    cout << "AU AU!!" << endl;
}
