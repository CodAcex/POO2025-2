#include "Figurinha.h"
#include <iostream>

using namespace std;

Figurinha::Figurinha()
{
    this->nro = 0;
    this->nome = "VAZIO";
    this->time = "";
    this->status = 0;
}

Figurinha::Figurinha(int nro, string nome, string time)
{
    this->nro = nro;
    this->nome = nome;
    this->time = time;
    this->status = 0; // Inicialmente, não colada/repetida
    this->nroPagina = 0;
}

Figurinha::~Figurinha()
{
}

// Getters (Sem const)
int Figurinha::getNro() { return this->nro; }
string Figurinha::getNome() { return this->nome; }
string Figurinha::getTime() { return this->time; }
int Figurinha::getStatus() { return this->status; }
int Figurinha::getNroPagina() { return this->nroPagina; }

string Figurinha::getNomeStatus()
{
     if (this->status == FIG_NA_COLECAO) {
        return "Repetida/Nao Colada";
    } else if (this->status == FIG_COLADA) {
        return "COLADA NO ALBUM";
    } else if (this->status == FIG_PARA_TROCA) {
        return "DISPONIVEL PARA TROCA";
    } else {
        return "Status Desconhecido";
    }
}

// Setters
void Figurinha::setStatus(int status) { this->status = status; }
void Figurinha::setNroPagina(int nroPagina) { this->nroPagina = nroPagina; }