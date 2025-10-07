#include "Data.h"

Data::Data(int d, int m, int a)
{
    dia = d;
    mes = m;
    ano = a;
}

Data::~Data()
{
}

void Data::imprimirData()
{

    cout << dia << "/" << mes << "/" << ano;
}

void Data::imprimirDataPorExtenso(string cidade)
{
    string meses[12] = {"janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
    
    cout << cidade << ", " << dia << " de " << meses[mes-1] << " de " << ano << ".";
}