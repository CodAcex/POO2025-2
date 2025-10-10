#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include "Figurinha.h"
#include "Pagina.h"
#include "Troca.h"

using namespace std;

class Album {
private:
    Figurinha figurinhas[100]; 
    int quantidade;
    Pagina paginas[20];
    int nroPaginas;
    Troca trocas[10]; 
    int nroTrocas;
    
    void inicializarPaginas();
    
    Pagina* encontrarPagina(int nroFigurinha); 
    Figurinha* encontrarFigurinha(int nro, int statusDesejado); 

public:
    Album();
    ~Album();

    void adicionar(Figurinha f); 
    bool possui(int nro);
    void colarFigurinha(int nro); 
    void disponibilizarParaTroca(int nro); 
    void abrirPacote();
    void listarFigurinhasDisponiveis(); 
    void revisarSolicitacoes();
    Pagina& getPagina(int index);
    void listarFigurinhasColecionaveis(); 
    void salvar(string nomeUsuario);
    void carregar(string nomeUsuario);
};

#endif
