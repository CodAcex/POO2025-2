#include "Troca.h"
#include <iostream>

using namespace std;

Troca::Troca()
{
    this->status = TROCA_AGUARDANDO;
}
Troca::Troca(string proponente, int requerida, int disponivel)
{
    this->nomeProponente = proponente;
    this->figurinhaRequerida = requerida;
    this->figurinhaDisponivel = disponivel;
    this->status = TROCA_AGUARDANDO; 
}
Troca::~Troca()
{

}

// Getters
string Troca::getNomeProponente() 
{ 
    return this->nomeProponente; 
}
int Troca::getFigurinhaRequerida()
{ 
    return this->figurinhaRequerida; 
}
int Troca::getFigurinhaDisponivel() 
{ 
    return this->figurinhaDisponivel; 
}
int Troca::getStatus() 
{ 
    return this->status; 
}

void Troca::aceitar(bool aceite) 
{
    if (aceite) 
    {
        this->status = TROCA_ACEITA;
    } 
    else 
    {
        this->status = TROCA_RECUSADA;
    }
}