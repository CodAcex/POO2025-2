#include "Pagina.h"
#include <iostream>

using namespace std;

Pagina::Pagina()
{

    this->titulo = "";
    this->nroInicial = 0;
    this->nroFinal = 0;
    this->nroFigurinhas = 0;
}

Pagina::Pagina(string titulo, int nroInicial, int nroFinal)
{
    this->titulo = titulo;
    this->nroInicial = nroInicial;
    this->nroFinal = nroFinal;
    this->nroFigurinhas = 0;
    
}

Pagina::~Pagina()
{
    
}


int Pagina::getNroInicial() 
{ 
    return this->nroInicial; 
}
int Pagina::getNroFinal() 
{
    return this->nroFinal; 
}
void Pagina::adicionarFigurinha(Figurinha f) 
{
    int posicao = f.getNro() - this->nroInicial;
    
    if (posicao >= 0 && posicao < MAX_FIGURINHAS_PAGINA) 
    {
        this->figurinhasNaPagina[posicao] = f;
         this->nroFigurinhas++; 
    }
}

void Pagina::listar() 
{
    cout << "\n--- PAGINA: " << this->titulo << " (Nros " << this->nroInicial << " a " << this->nroFinal << ") ---" << endl;
    
    for (int i = 0; i < MAX_FIGURINHAS_PAGINA; ++i) 
    {
        int nroEsperado = this->nroInicial + i;
        if (this->figurinhasNaPagina[i].getNro() == nroEsperado) 
        {
            cout << "[X] #" << nroEsperado << " - " << this->figurinhasNaPagina[i].getNome() << endl;
        } 
        else 
        {
            cout << "[ ] #" << nroEsperado << " - Vazio" << endl;
        }
    }
    cout << "-----------------------------------------------------" << endl;
}
