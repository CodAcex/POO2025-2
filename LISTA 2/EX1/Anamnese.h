#ifndef ANAMNESE_H
#define ANAMNESE_H

#include <string>
using namespace std;

class Anamnese
{
private:
    string nome;
    int idade;
    double pesoKg;
    double alturaM;
    string alergias;
    string doencasPreExistentes;
    string medicamentosEmUso;

public:
    // Construtor padrão
    Anamnese();

    // Construtor com todos os campos
    Anamnese(string nome, int idade, double pesoKg, double alturaM,
             string alergias, string doencasPreExistentes, string medicamentosEmUso);

    // Getters
    string getNome();
    int getIdade();
    double getPesoKg();
    double getAlturaM();
    string getAlergias();
    string getDoencasPreExistentes();
    string getMedicamentosEmUso();

    // Setters
    void setNome(string nome);
    void setIdade(int idade);
    void setPesoKg(double pesoKg);
    void setAlturaM(double alturaM);
    void setAlergias(string alergias);
    void setDoencasPreExistentes(string doencasPreExistentes);
    void setMedicamentosEmUso(string medicamentosEmUso);

    // Métodos adicionais
    double calcularIMC();
    string gerarResumo();
};

#endif // ANAMNESE_H