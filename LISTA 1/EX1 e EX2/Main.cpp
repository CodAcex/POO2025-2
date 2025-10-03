#include "Mago.h"

int main()
{
    Mago mago; // instanciando um objeto da classe mago.

    // Invocando os métodos 
    mago.andar();
    mago.falar("Ola mundo da OO!");
    mago.invocarMagia();

    //Alterar o nome do objeto mago invocando o método setter alterarNome
    mago.alterarNome("Merlin");
    mago.alterarIdade(100);
    
    mago.falar("");

    // Instanciando objetos utilizando o construtor parametrizado
    Mago mago2("Harry Potter",12,"Hogwarts");
    Mago mago3("Gandalf",300,"Mordor");

    mago2.falar("Ola!");
    mago3.falar("Ola!");

    // Usando os novos métodos
    mago.treinarMagia(5);
    mago2.treinarMagia(10);
    mago3.treinarMagia(20);

    mago.mostrarVarinha();
    mago2.mostrarVarinha();
    mago3.mostrarVarinha();
    
    // Comparando idades para descobrir o mais novo
    int menorIdade;
    string maisNovo;
    if(mago.retornarIdade() < mago2.retornarIdade())
    {
        menorIdade = mago.retornarIdade();
        maisNovo = mago.retornarNome();
    }
    else if(mago2.retornarIdade() < mago3.retornarIdade())
    {
        menorIdade = mago2.retornarIdade();
        maisNovo = mago2.retornarNome();
    }
    else
    {
        menorIdade = mago3.retornarIdade();
        maisNovo = mago3.retornarNome();
    }

    cout << "O mago mais novo chama-se " << maisNovo << " e sua idade é " << menorIdade << endl;

    getchar(); // Espera apertar uma tecla
    return 0;
}