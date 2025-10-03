#include <iostream>
#include <string>

using namespace std;

class Mago 
{
// Atributos
private:
    string nome;
    int idade;
    string escolaDeMagia;

    // Novos atributos
    int nivelPoder;
    string varinha;

// Métodos
public:
    Mago(); //Construtor padrão
    Mago(string nome, int idade, string escolaDeMagia);
    ~Mago(); //Destrutor

    //Métodos setters
    void alterarNome(string nome);
    void alterarIdade(int idade);

    //Métodos getters
    int retornarIdade();
    string retornarNome();

    // Métodos já existentes
    void andar();
    void falar(string msg);
    void invocarMagia();

    // 🔹 Novos métodos
    void treinarMagia(int horas);
    void mostrarVarinha();
};