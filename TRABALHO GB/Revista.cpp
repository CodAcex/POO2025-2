#include "Revista.h"
#include <iostream>

using namespace std;

Revista::Revista(int _id, string _titulo, int _ano, int _edicao, string _periodicidade) : ItemAcervo(_id, _titulo, _ano, false), edicao(_edicao), periodicidade(_periodicidade) 
{

}


Revista::~Revista() 
{

}


float Revista::calcularTaxaAtraso(int dias) 
{
float taxaPorDia = 0.5;
return taxaPorDia * dias;
}


void Revista::mostrar() 
{
cout << "[Revista] ID:" << id << " | " << titulo << endl;
cout << "Ano:" << ano << endl;
cout << "Edicao:" << edicao << endl;
cout << "Periodicidade:" << periodicidade << endl;
if (emprestado == true)
cout << "Emprestado" << "\n" << endl;
else 
cout << "Disponivel" << "\n" << endl;
}


string Revista::toCSV() 
{
string s = "Revista;" + to_string(id) + ";" + titulo + ";" + to_string(ano) + ";" + to_string(edicao) + ";" + periodicidade + ";" + (emprestado ? "1" : "0");
return s;
}