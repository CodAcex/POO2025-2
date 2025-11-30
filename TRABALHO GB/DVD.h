#ifndef DVD_ITEM_H
#define DVD_ITEM_H

using namespace std;

#include "MidiaDigital.h"


// DVD herda de MidiaDigital (heranca multinivel)
class DVDItem : public MidiaDigital {
string regiao; // ex: "Region 1"


public:
DVDItem(int _id, string _titulo, int _ano, string _formato, string _regiao);
virtual ~DVDItem();


virtual float calcularTaxaAtraso(int dias);
virtual void mostrar();
virtual string toCSV();
};


#endif // DVD_ITEM_HPP