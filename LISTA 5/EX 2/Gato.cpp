#include "Gato.h"

Gato::Gato(string nome, string Som_Bicho) : Animal(nome, Som_Bicho)
{
    cout << "Gato " << nome << " foi criado" << endl;
    cout << Som_Bicho << endl;
}

void Gato::fazerSom()
{
    cout << "MIAU" << endl;
}
