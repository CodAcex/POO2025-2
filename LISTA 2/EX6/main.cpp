#include "FrequenciaCardiaca.h"
#include <iostream>
using namespace std;

int main() {
    string nome, sobrenome;
    int dia, mes, ano;
    int diaAtual, mesAtual, anoAtual;

    cout << "=== Cadastro Frequencia Cardiaca ===" << endl;
    cout << "Digite seu primeiro nome: ";
    cin >> nome;
    cout << "Digite seu sobrenome: ";
    cin >> sobrenome;
    cout << "Digite sua data de nascimento (dia mes ano): ";
    cin >> dia >> mes >> ano;

    cout << "Digite a data atual (dia mes ano): ";
    cin >> diaAtual >> mesAtual >> anoAtual;

    // Instancia objeto
    FrequenciaCardiaca pessoa(nome, sobrenome, dia, mes, ano);

    // Calcula idade
    int idade = pessoa.obterIdade(diaAtual, mesAtual, anoAtual);

    // Frequência máxima
    int freqMax = pessoa.obterFrequenciaMaxima(idade);

    // Frequência ideal
    int minAlvo, maxAlvo;
    pessoa.obterFrequenciaIdeal(idade, minAlvo, maxAlvo);

    // Exibir resultados
    cout << "\n=== Resultados ===" << endl;
    cout << "Nome completo: " << pessoa.getPrimeiroNome() << " " << pessoa.getSobrenome() << endl;
    cout << "Data de nascimento: " << pessoa.getDiaNasc() << "/" << pessoa.getMesNasc() << "/" << pessoa.getAnoNasc() << endl;
    cout << "Idade: " << idade << " anos" << endl;
    cout << "Frequencia cardiaca maxima: " << freqMax << " bpm" << endl;
    cout << "Faixa de frequencia ideal: " << minAlvo << " - " << maxAlvo << " bpm" << endl;

    return 0;
}