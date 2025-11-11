#include "MagoBranco.h"

MagoBranco::MagoBranco(string nome, int idade, string escolaDeMagia) : Mago(nome,idade,escolaDeMagia)
{
    poderCura = 0;
    cout << "Mago Branco" << nome << " foi Criado" << endl;
}

void MagoBranco::LancarCura()
{
    cout << "Curando" << endl;
}
