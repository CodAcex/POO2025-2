#include "Pagina.h"
#include <iostream>

using namespace std;

// Construtor Padrão (Necessário para o array de páginas dentro da classe Album)
Pagina::Pagina()
{
    // O array figurinhasNaPagina[] é inicializado automaticamente 
    // com Figurinha::Figurinha(), que deve definir nro=0.
    this->titulo = "";
    this->nroInicial = 0;
    this->nroFinal = 0;
    this->nroFigurinhas = 0;
}

// Construtor com Parâmetros
Pagina::Pagina(string titulo, int nroInicial, int nroFinal)
{
    this->titulo = titulo;
    this->nroInicial = nroInicial;
    this->nroFinal = nroFinal;
    this->nroFigurinhas = 0;
    
    // As 10 posições do array figurinhasNaPagina[] são automaticamente inicializadas
    // com Figurinha::Figurinha(), que define nro=0.
}

Pagina::~Pagina()
{
    // Não há necessidade de liberar memória dinâmica.
}

// IMPLEMENTAÇÃO DOS GETTERS
int Pagina::getNroInicial() { return this->nroInicial; }
int Pagina::getNroFinal() { return this->nroFinal; }

// Adiciona a figurinha colada ao slot correto da página
void Pagina::adicionarFigurinha(Figurinha f) {
    // Calcula a posição do array (0 a 9)
    int posicao = f.getNro() - this->nroInicial;
    
    // Verifica se a posição é válida para esta página
    if (posicao >= 0 && posicao < MAX_FIGURINHAS_PAGINA) {
        // Copia o objeto Figurinha para a posição correta.
        this->figurinhasNaPagina[posicao] = f;
        
        // Se você quiser manter a contagem de figurinhas coladas por página:
        // this->nroFigurinhas++; 
    }
}

// Exibe a página, mostrando [X] para as figurinhas coladas
void Pagina::listar() {
    cout << "\n--- PAGINA: " << this->titulo << " (Nros " << this->nroInicial << " a " << this->nroFinal << ") ---" << endl;
    
    for (int i = 0; i < MAX_FIGURINHAS_PAGINA; ++i) {
        int nroEsperado = this->nroInicial + i;
        
        // Verifica se a figurinha na posição 'i' tem o Nro esperado.
        // Se foi colada/desserializada, figurinhasNaPagina[i].getNro() == nroEsperado.
        // Se não foi colada, figurinhasNaPagina[i].getNro() == 0 (do construtor de Figurinha).
        if (this->figurinhasNaPagina[i].getNro() == nroEsperado) {
            cout << "[X] #" << nroEsperado << " - " << this->figurinhasNaPagina[i].getNome() << endl;
        } else {
            cout << "[ ] #" << nroEsperado << " - Vazio" << endl;
        }
    }
    cout << "-----------------------------------------------------" << endl;
}