#include "DVD.h"
#include <iostream>

using namespace std;

DVDItem::DVDItem(int _id, string _titulo, int _ano, string _formato, string _regiao) : MidiaDigital(_id, _titulo, _ano, _formato), regiao(_regiao) 
{

}

DVDItem::~DVDItem() 
{

}

float DVDItem::calcularTaxaAtraso(int dias) 
{
float base = MidiaDigital::calcularTaxaAtraso(dias);
float acrescimo = 0.5 * dias;
return base + acrescimo;
}


void DVDItem::mostrar() 
{
cout << "[DVD] ID:" << id << " | " << titulo << endl;
cout<< "Ano:" << ano << endl;
cout<< "Formato:" << formato << endl;
cout << "Regiao:" << regiao << endl;
if (emprestado == true) 
cout << "Emprestado" "\n" << endl;
else 
cout << "Disponivel" "\n" << endl;
}


string DVDItem::toCSV() 
{
string s = "DVD;" + to_string(id) + ";" + titulo + ";" + to_string(ano) + ";" + formato + ";" + regiao + ";" + (emprestado ? "1" : "0");
return s;
}