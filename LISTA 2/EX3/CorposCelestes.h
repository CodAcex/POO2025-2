#ifndef CORPOCELESTE_H
#define CORPOCELESTE_H

#include <string>
using namespace std;

// Enumeração auxiliar
enum class TipoCorpo { Estrela, Planeta, Lua, Asteroide, Cometa, Outro };

class CorpoCeleste
{
private:
    string nome;
    TipoCorpo tipo;
    double massaKg;
    double raioKm;

public:
    // Construtor padrão
    CorpoCeleste();

    // Construtor com parâmetros
    CorpoCeleste(string nome, TipoCorpo tipo, double massaKg, double raioKm);

    // Getters
    string getNome();
    TipoCorpo getTipo();
    double getMassaKg();
    double getRaioKm();

    // Setters
    void setNome(string nome);
    void setTipo(TipoCorpo tipo);
    void setMassaKg(double massaKg);
    void setRaioKm(double raioKm);

    // Métodos adicionais
    double calcularDensidade();
    double gravidadeSuperficial();
    string descricao();
};

#endif