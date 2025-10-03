#ifndef SMARTHOUSE_H
#define SMARTHOUSE_H

#include <string>
using namespace std;

class SmartHouse
{
private:
    bool luzesLigadas;
    double temperaturaDesejada;
    bool alarmeAtivo;
    bool portaTrancada;
    string modo; // Ex: "Normal", "Férias", "Noite"

public:
    // Construtor padrão
    SmartHouse();

    // Construtor com parâmetros
    SmartHouse(bool luzesLigadas, double temperaturaDesejada, bool alarmeAtivo, bool portaTrancada, string modo);

    // Métodos principais
    void ligarLuzes();
    void desligarLuzes();

    void setTemperaturaDesejada(double temperatura);
    double getTemperaturaDesejada();

    void ativarAlarme();
    void desativarAlarme();

    void trancarPorta();
    void destrancarPorta();

    void setModo(string modo);
    string getModo();

    // Métodos adicionais
    string status();
    void aplicarCena(string cena);
};

#endif 