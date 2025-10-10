#ifndef TROCA_H
#define TROCA_H

#include <string>

// === DEFINIÇÕES DE STATUS DA TROCA ===
#define TROCA_AGUARDANDO    0
#define TROCA_ACEITA        1
#define TROCA_RECUSADA      2
// ===========================================

using namespace std;

class Troca {
private:
    string nomeProponente;
    int figurinhaRequerida;
    int figurinhaDisponivel;
    int status; 
    
public:
    Troca();
    Troca(string nomeProponente, int requerida, int disponivel);
    ~Troca(); // Destrutor declarado

    // Getters: AGORA APENAS DECLARAÇÕES
    int getStatus();
    string getNomeProponente();
    int getFigurinhaRequerida();
    int getFigurinhaDisponivel();
    
    // Método
    void aceitar(bool aceita);
};

#endif // TROCA_H