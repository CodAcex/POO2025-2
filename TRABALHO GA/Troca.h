#ifndef TROCA_H
#define TROCA_H

#include <string>

using namespace std;

class Troca {
private:
    string nomeProponente;
    int figurinhaRequerida;
    int figurinhaDisponivel;
    int status; // 0: Pendente, 1: Aceita, 2: Recusada

public:
    // Construtor
    Troca();
    Troca(string proponente, int requerida, int disponivel);
    ~Troca();
    
    // Métodos (Sem const)
    string getNomeProponente();
    int getFigurinhaRequerida();
    int getFigurinhaDisponivel();
    int getStatus();

    void aceitar(bool aceite);
};

#endif // TROCA_H