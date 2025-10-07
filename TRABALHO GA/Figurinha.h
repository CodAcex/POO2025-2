#ifndef FIGURINHA_H
#define FIGURINHA_H

#include <string>

using namespace std;

class Figurinha {
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
    
    // Métodos (Sem const)
    int getNro();
    string getNome();
    string getTime();
    int getStatus();
    int getNroPagina();

    void setStatus(int status);
    void setNroPagina(int nroPagina);
};

#endif // FIGURINHA_H