#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "Album.h"

using namespace std;

class Usuario {
private:
    string nomeDeUsuario;
    string senha;
    Album meuAlbum;

public:
    Usuario() {}

    void cadastrar(string nome, string senha);
    bool verificarLogin(string nome, string senha);

    string getNomeDeUsuario();
    string getSenha();
    Album& getAlbum();
};

#endif 
