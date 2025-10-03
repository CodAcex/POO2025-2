#include "FrequenciaCardiaca.h"
#include <iostream>
using namespace std;

FrequenciaCardiaca::FrequenciaCardiaca()
: primeiroNome(""), sobrenome(""), diaNasc(1), mesNasc(1), anoNasc(1900) {}

FrequenciaCardiaca::FrequenciaCardiaca(string primeiroNome, string sobrenome, int dia, int mes, int ano)
{
    this->primeiroNome = primeiroNome;
    this->sobrenome = sobrenome;
    setDiaNasc(dia);
    setMesNasc(mes);
    setAnoNasc(ano);
}

// Getters
string FrequenciaCardiaca::getPrimeiroNome() { return primeiroNome; }
string FrequenciaCardiaca::getSobrenome() { return sobrenome; }
int FrequenciaCardiaca::getDiaNasc() { return diaNasc; }
int FrequenciaCardiaca::getMesNasc() { return mesNasc; }
int FrequenciaCardiaca::getAnoNasc() { return anoNasc; }

// Setters
void FrequenciaCardiaca::setPrimeiroNome(string nome) { this->primeiroNome = nome; }
void FrequenciaCardiaca::setSobrenome(string sobrenome) { this->sobrenome = sobrenome; }

void FrequenciaCardiaca::setDiaNasc(int dia) {
    if(dia >= 1 && dia <= 31)
        this->diaNasc = dia;
    else
        this->diaNasc = 1; // valor padrão
}

void FrequenciaCardiaca::setMesNasc(int mes) {
    if(mes >= 1 && mes <= 12)
        this->mesNasc = mes;
    else
        this->mesNasc = 1;
}

void FrequenciaCardiaca::setAnoNasc(int ano) {
    if(ano > 1900)
        this->anoNasc = ano;
    else
        this->anoNasc = 1900;
}

// Métodos principais
int FrequenciaCardiaca::obterIdade(int diaAtual, int mesAtual, int anoAtual) {
    int idade = anoAtual - anoNasc;
    if(mesAtual < mesNasc || (mesAtual == mesNasc && diaAtual < diaNasc)) {
        idade--; // ainda não fez aniversário
    }
    return idade;
}

int FrequenciaCardiaca::obterFrequenciaMaxima(int idade) {
    return 220 - idade;
}

void FrequenciaCardiaca::obterFrequenciaIdeal(int idade, int& minAlvo, int& maxAlvo) {
    int maxima = obterFrequenciaMaxima(idade);
    minAlvo = (int)(maxima * 0.50);
    maxAlvo = (int)(maxima * 0.85);
}