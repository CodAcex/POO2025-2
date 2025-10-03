#ifndef ASSISTENTEVIRTUAL_H
#define ASSISTENTEVIRTUAL_H

#include <string>
using namespace std;

class AssistenteVirtual
{
private:
    string nome;
    string idioma;
    string versao;
    int volume;            // nível de volume (0 a 100, por exemplo)
    bool microfoneAtivo;

public:
    // Construtor padrão
    AssistenteVirtual();

    // Construtor com parâmetros
    AssistenteVirtual(string nome, string idioma, string versao, int volume, bool microfoneAtivo);

    // Métodos principais
    void dizerOla();
    void executarComando(string comando);
    void definirIdioma(string idioma);
    void atualizarVersao(string novaVersao);

    // Getters
    string getNome();
    string getIdioma();
    string getVersao();
    int getVolume();
    bool getMicrofoneAtivo();

    // Setters
    void setNome(string nome);
    void setIdioma(string idioma);
    void setVersao(string versao);
    void setVolume(int volume);
    void setMicrofoneAtivo(bool ativo);

    // Métodos adicionais
    void registrarLembrete(string lembrete);
    string resumoStatus();
};

#endif