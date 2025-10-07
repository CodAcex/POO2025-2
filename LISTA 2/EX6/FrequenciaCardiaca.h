#include <string>
using namespace std;

class FrequenciaCardiaca {
private:
    string primeiroNome;
    string sobrenome;
    int diaNasc;
    int mesNasc;
    int anoNasc;

public:
    FrequenciaCardiaca();
    FrequenciaCardiaca(string nome, string sobrenome, int dia, int mes, int ano);

    string getPrimeiroNome();
        string
        getSobrenome();

        int getDiaNasc();

        int getMesNasc();

        int getAnoNasc();

        // Setters e Getters
        void setPrimeiroNome(string nome);
        string getPrimeiroNome() const;

        void setSobrenome(string snome);
        string getSobrenome() const;

        void setDiaNasc(int dia);
        int getDiaNasc() const;

        void setMesNasc(int mes);
        int getMesNasc() const;

        void setAnoNasc(int ano);
        int obterIdade(int diaAtual, int mesAtual, int anoAtual);
        int obterFrequenciaMaxima(int idade);
        void obterFrequenciaIdeal(int idade, int &minAlvo, int &maxAlvo);
        int getAnoNasc() const;

        // Métodos
        int obterIdade(int diaAtual, int mesAtual, int anoAtual) const;
        int obterFrequenciaMaxima(int idade) const;                             // 220 - idade
        void obterFrequenciaIdeal(int idade, int &minAlvo, int &maxAlvo) const; // 50% - 85%
};