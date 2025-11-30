#ifndef MIDIA_DIGITAL_H
#define MIDIA_DIGITAL_H

using namespace std;

#include "ItemAcervo.h"


class MidiaDigital : public ItemAcervo 
{
protected:
string formato;


public:
MidiaDigital(int _id, string _titulo, int _ano, string _formato);
virtual ~MidiaDigital();


virtual float calcularTaxaAtraso(int dias);
virtual void mostrar();
virtual string toCSV();
};


#endif // MIDIA_DIGITAL_H