#ifndef PAGINA_H
#define PAGINA_H

#include <string>
#include "Figurinha.h"

using namespace std;

#define MAX_FIGURINHAS_PAGINA 10 // Capacidade de figurinhas por página

class Pagina {
private:
    string titulo;
    int nroInicial;
    int nroFinal;
    Figurinha figurinhasNaPagina[MAX_FIGURINHAS_PAGINA]; // Figurinhas coladas
    int nroFigurinhas;

public:
    // Construtor
    Pagina();
    Pagina(string titulo, int nroInicial, int nroFinal);
    ~Pagina();
    
    // NOVO: Getters que o Album precisa (Sem const)
    int getNroInicial();
    int getNroFinal();
    
    // Métodos
    void adicionarFigurinha(Figurinha f);
    void listar();
};

#endif // PAGINA_H