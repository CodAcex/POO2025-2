#include "Usuario.h"

using namespace std;

void Usuario::cadastrar(string nome, string senha) {
    this->nomeDeUsuario = nome;
    this->senha = senha;
    // meuAlbum é inicializado automaticamente pelo construtor padrão
}

bool Usuario::verificarLogin(string nome, string senha) {
    return (this->nomeDeUsuario == nome && this->senha == senha);
}

// Getters (Sem const)
string Usuario::getNomeDeUsuario() { return this->nomeDeUsuario; }
string Usuario::getSenha() { return this->senha; }
Album& Usuario::getAlbum() { return this->meuAlbum; }