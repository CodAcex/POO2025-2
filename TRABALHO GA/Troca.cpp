#include "Troca.h"

using namespace std;

Troca::Troca()
{
}

Troca::Troca(string proponente, int requerida, int disponivel)
{
    this->nomeProponente = proponente;
    this->figurinhaRequerida = requerida;
    this->figurinhaDisponivel = disponivel;
    this->status = 0; // Pendente
}
Troca::~Troca(){}

// Getters (Sem const)
string Troca::getNomeProponente() { return this->nomeProponente; }
int Troca::getFigurinhaRequerida() { return this->figurinhaRequerida; }
int Troca::getFigurinhaDisponivel() { return this->figurinhaDisponivel; }
int Troca::getStatus() { return this->status; }

void Troca::aceitar(bool aceite) {
    if (aceite) {
        // Status 1: Aceita
        this->status = 1;
    } else {
        // Status 2: Recusada
        this->status = 2;
    }
}