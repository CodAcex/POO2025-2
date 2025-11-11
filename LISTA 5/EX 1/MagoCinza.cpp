#include "MagoCinza.h"

MagoCinza::MagoCinza(string nome, int idade, string escolaDeMagia) : Mago(nome,idade,escolaDeMagia)
{
    PocaoCura = 0;
    cout << "Mago Cinza" << nome << " criado" << endl;
}

void MagoCinza::PrepararPocao()
{
    cout << "Criando a Poção de Cura" << endl;
}