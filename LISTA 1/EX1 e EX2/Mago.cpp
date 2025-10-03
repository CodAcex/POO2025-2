#include "Mago.h"

Mago::Mago()
:nome(""),idade(0),escolaDeMagia(""),nivelPoder(1),varinha("Desconhecida")
{
    cout << "Mago criado com construtor padrão!" << endl;
}

Mago::Mago(string nome, int idade, string escolaDeMagia)
{
    this->nome = nome;
    this->idade = idade;
    this->escolaDeMagia = escolaDeMagia;
    this->nivelPoder = 1;
    this->varinha = "Desconhecida";
}

Mago::~Mago()
{
    cout << "Deixou de existir!" << endl;
}

void Mago::alterarNome(string nome)
{
    this->nome = nome;
}

void Mago::alterarIdade(int idade)
{
    this->idade = idade;
}

int Mago::retornarIdade()
{
    return idade;
}

string Mago::retornarNome()
{
    return nome;
}

void Mago::andar()
{ 
    cout << "Estou andando!" << endl;
}

void Mago::falar(string msg)
{
    cout << "Meu nome é " << this->nome << endl;
    cout << msg << endl;
}

void Mago::invocarMagia()
{
    cout << "Invocando magia!" << endl;
}

// 🔹 Novos métodos
void Mago::treinarMagia(int horas)
{
    nivelPoder += horas;
    cout << nome << " treinou por " << horas << " horas e agora tem nível de poder " << nivelPoder << "!" << endl;
}

void Mago::mostrarVarinha()
{
    cout << nome << " possui uma varinha: " << varinha << endl;
}