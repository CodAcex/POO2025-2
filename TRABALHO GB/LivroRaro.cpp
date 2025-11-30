#include "LivroRaro.h"
#include <iostream>

using namespace std;

LivroRaro::LivroRaro(int _id, string _titulo, int _ano, string _autor, int _paginas, string _condicao) : Livro(_id, _titulo, _ano, _autor, _paginas), condicao(_condicao) 
{

}


LivroRaro::~LivroRaro() 
{

}


float LivroRaro::calcularTaxaAtraso(int dias) 
{
float taxaBase = Livro::calcularTaxaAtraso(dias);
float multiplicador = 3.0; 
return taxaBase * multiplicador;
}


void LivroRaro::mostrar() 
{
cout << "[LivroRaro] ID:" << id << " | " << titulo << endl;
cout <<"Ano:" << ano << endl;
cout << "Autor:" << autor << endl;
cout << "Paginas:" << paginas << endl;
cout << "Condicao:" << condicao << endl;
if (emprestado == true) 
cout << "Emprestado" << "\n" << endl;
else 
cout << "Disponivel" << "\n" << endl;
}


string LivroRaro::toCSV() 
{
string s = "LivroRaro;" + to_string(id) + ";" + titulo + ";" + to_string(ano) + ";" + autor + ";" + to_string(paginas) + ";" + condicao + ";" + (emprestado ? "1" : "0");
return s;
}