#ifndef ITEMACERVO_H
#define ITEMACERVO_H

using namespace std;

#include <string>

class ItemAcervo {
protected:
int id; 
string titulo; 
int ano;
bool emprestado; 


public:
ItemAcervo(int _id, string _titulo, int _ano, bool _emprestado);
virtual ~ItemAcervo();
int getId();
string getTitulo();
int getAno();
bool isEmprestado();

void setTitulo(string t);
void setAno(int a);
void emprestar();
void devolver();
virtual float calcularTaxaAtraso(int dias) = 0;
virtual void mostrar() = 0;
virtual string toCSV();
};


#endif // ITEM_ACERVO_H