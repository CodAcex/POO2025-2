#include "MagoRoxo.h"

MagoRoxo::MagoRoxo(string nome, int idade, string escolaDeMagia) : Mago(nome,idade,escolaDeMagia)
{
    Ilusao = 0;
    cout << "Mago Roxo" << nome << " criado com sucesso" << endl;
}

void MagoRoxo::CriarIlusao()
{
    cout << "Ilusao sendo Criada" << endl;
}