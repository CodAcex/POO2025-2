#include "MagoVerde.h"

MagoVerde::MagoVerde(string nome, int idade, string escolaDeMagia) : Mago(nome,idade,escolaDeMagia)
{
    falarCachorro = "...";
    cout << "Mago Verde" << nome << " criado com sucesso";
}

void MagoVerde::FalarComAnimais()
{
    cout << "Falando" << endl;
}