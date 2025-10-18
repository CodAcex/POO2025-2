#include "Usuario.h"

using namespace std;

Usuario::Usuario()
{
}

Usuario::~Usuario()
{
}

void Usuario::cadastrar(string nome, string senha)
{
    this->nomeDeUsuario = nome;
    this->senha = senha;
}

bool Usuario::verificarLogin(string nome, string senha) 
{
    return (this->nomeDeUsuario == nome && this->senha == senha);
}

string Usuario::getNomeDeUsuario() 
{ 
    return this->nomeDeUsuario; 
}
string Usuario::getSenha() 
{ 
    return this->senha; 
}
Album& Usuario::getAlbum() 
{ 
    return this->meuAlbum; 
}
