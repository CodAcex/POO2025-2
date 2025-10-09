#ifndef PAGINA_H
#define PAGINA_H

#include <string>
#include "Figurinha.h"

using namespace std;

#define MAX_FIGURINHAS_PAGINA 10 

class Pagina {
private:
    string titulo;
    int nroInicial;
    int nroFinal;
    Figurinha figurinhasNaPagina[MAX_FIGURINHAS_PAGINA];
    int nroFigurinhas;

public:
    
    Pagina();
    Pagina(string titulo, int nroInicial, int nroFinal);
    ~Pagina();
    
    int getNroInicial();
    int getNroFinal();
    void adicionarFigurinha(Figurinha f);
    void listar();
};

#endif
