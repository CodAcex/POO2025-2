#ifndef LIVRO_H
#define LIVRO_H

using namespace std;

#include "ItemAcervo.h"


// Livro herda de ItemAcervo (heranca simples)
class Livro : public ItemAcervo {
protected:
string autor;
int paginas;


public:
Livro(int _id, string _titulo, int _ano, string _autor, int _paginas);
Livro(int _id, string _titulo);


virtual ~Livro();


virtual float calcularTaxaAtraso(int dias);
virtual void mostrar();


virtual string toCSV();
};


#endif // LIVRO_H