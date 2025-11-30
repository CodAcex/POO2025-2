#include "ItemAcervo.h"

using namespace std;

ItemAcervo::ItemAcervo(int _id, string _titulo, int _ano, bool _emprestado) : id(_id), titulo(_titulo), ano(_ano), emprestado(_emprestado) 
{

}


ItemAcervo::~ItemAcervo() 
{

}


int ItemAcervo::getId() 
{ 
    return id; 
}
string ItemAcervo::getTitulo() 
{ 
    return titulo; 
}
int ItemAcervo::getAno() 
{ 
    return ano; 
}
bool ItemAcervo::isEmprestado() 
{ 
    return emprestado; 
}


void ItemAcervo::setTitulo(string t) 
{ 
    titulo = t; 
}
void ItemAcervo::setAno(int a) 
{ 
    ano = a; 
}


void ItemAcervo::emprestar() 
{ if (emprestado == false) 
    emprestado = true; 
}
void ItemAcervo::devolver() 
{ 
    emprestado = false; 
}

string ItemAcervo::toCSV() 
{
string s = "ItemAcervo;" + to_string(id) + ";" + titulo + ";" + to_string(ano) + ";" + (emprestado ? "1" : "0");
return s;
}