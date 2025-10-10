#ifndef FIGURINHA_H
#define FIGURINHA_H

#define FIG_NA_COLECAO      0   // Repetida
#define FIG_COLADA          1   // Colada no álbum
#define FIG_PARA_TROCA      2   // Disponível para troca

#include <string>

using namespace std;

class Figurinha 
{
private:
    int nro;
    string nome;
    string time;
    int status;     // 0: Não Colada/Repetida, 1: Colada, 2: Disponível para Troca
    int nroPagina;  // Número da página onde deve ser colada

public:
    // Construtor
    Figurinha();
    Figurinha(int nro, string nome, string time);
    ~Figurinha();
    
    int getNro();
    string getNome();
    string getTime();
    int getStatus();
    int getNroPagina();
    string getNomeStatus();

    void setStatus(int status);
    void setNroPagina(int nroPagina);
};

#endif
