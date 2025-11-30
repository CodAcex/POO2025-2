#include "MidiaDigital.h"
#include <iostream>

using namespace std;

MidiaDigital::MidiaDigital(int _id, string _titulo, int _ano, string _formato) : ItemAcervo(_id, _titulo, _ano, false), formato(_formato) 
{

}


MidiaDigital::~MidiaDigital() 
{

}


float MidiaDigital::calcularTaxaAtraso(int dias) 
{
float taxaPorDia = 1.0;
return taxaPorDia * dias;
}


void MidiaDigital::mostrar() 
{
cout << "[MidiaDigital] ID:" << id << " | " << titulo << endl;
cout << "Ano:" << ano << endl;
cout << "Formato:" << formato << endl;
if (emprestado == true) 
cout << "Emprestado" << "\n" << endl;
else 
cout << "Disponivel" << "\n" << endl;
}


string MidiaDigital::toCSV() 
{
string s = "MidiaDigital;" + to_string(id) + ";" + titulo + ";" + to_string(ano) + ";" + formato + ";" + (emprestado ? "1" : "0");
return s;
}