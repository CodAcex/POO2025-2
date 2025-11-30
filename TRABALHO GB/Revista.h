#ifndef REVISTA_H
#define REVISTA_H

using namespace std;

#include "ItemAcervo.h"


class Revista : public ItemAcervo {
int edicao;
string periodicidade;

public:
Revista(int _id, string _titulo, int _ano, int _edicao, string _periodicidade);
virtual ~Revista();


virtual float calcularTaxaAtraso(int dias);
virtual void mostrar();
virtual string toCSV();
};


#endif // REVISTA_H