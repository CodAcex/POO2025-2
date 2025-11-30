#ifndef LIVRO_RARO_H
#define LIVRO_RARO_H

using namespace std;

#include "Livro.h"

class LivroRaro : public Livro {
string condicao; 


public:
LivroRaro(int _id, string _titulo, int _ano, string _autor, int _paginas, string _condicao);
virtual ~LivroRaro();


virtual float calcularTaxaAtraso(int dias);
virtual void mostrar();
virtual string toCSV();
};


#endif // LIVRORARO_H