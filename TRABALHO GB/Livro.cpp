#include "Livro.h"
#include <iostream>

using namespace std;

Livro::Livro(int _id, string _titulo, int _ano, string _autor, int _paginas) : ItemAcervo(_id, _titulo, _ano, false), autor(_autor), paginas(_paginas) {}


Livro::Livro(int _id, string _titulo) : ItemAcervo(_id, _titulo, 0, false), autor(""), paginas(0) {}


Livro::~Livro() {}

float Livro::calcularTaxaAtraso(int dias) {
float taxaPorDia = 1.5; 
return taxaPorDia * dias;
}


void Livro::mostrar() 
{
cout << "[Livro] ID:" << id << " | " << titulo << endl;
cout << "Ano: " << ano << endl; 
cout << "Autor: " << autor << endl; 
cout << "Paginas: " << paginas << endl;;
if (emprestado == true) 
cout << "Emprestado" << "\n" << endl;
else 
cout << "Disponivel" << "\n" << endl;
}


string Livro::toCSV() 
{
string s = "Livro;" + to_string(id) + ";" + titulo + ";" + to_string(ano) + ";" + autor + ";" + to_string(paginas) + ";" + (emprestado ? "1" : "0");
return s;
}