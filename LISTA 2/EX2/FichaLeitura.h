#ifndef FICHALEITURA_H
#define FICHALEITURA_H

#include <string>
using namespace std;

class FichaLeitura
{
private:
    string titulo;
    string autor;
    int anoPublicacao;
    int numPaginas;
    int paginaAtual;
    bool lido;
    double nota0a5;

public:
    // Construtor padrão
    FichaLeitura();

    // Construtor com todos os campos
    FichaLeitura(string titulo, string autor, int anoPublicacao, int numPaginas);

    // Métodos principais
    void iniciarLeitura();
    void marcarLido();
    void avancarPaginas(int paginas);
    void avaliar(double nota);

    // Getters
    string getTitulo();
    string getAutor();
    int getAnoPublicacao();
    int getNumPaginas();
    int getPaginaAtual();
    bool getLido();
    double getNota0a5();

    // Setters
    void setTitulo(string titulo);
    void setAutor(string autor);
    void setAnoPublicacao(int anoPublicacao);
    void setNumPaginas(int numPaginas);
    void setPaginaAtual(int paginaAtual);
    void setLido(bool lido);
    void setNota0a5(double nota);

    // Métodos adicionais
    double percentualLido();
    string resumo();
};

#endif 