#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

using namespace std;

#include <vector>
#include <string>
#include "ItemAcervo.h"
#include "Livro.h"
#include "LivroRaro.h"
#include "Revista.h"
#include "MidiaDigital.h"
#include "DVD.h"


class Biblioteca {
vector<ItemAcervo*> itens; // guarda ponteiros para objetos alocados com new
int proximoId;


public:
Biblioteca();
~Biblioteca();

int gerarId();
void adicionar(ItemAcervo* item);
ItemAcervo* buscarPorId(int id);
void listarTodos();
bool removerPorId(int id);


void salvarCSV(string arquivo);
void carregarCSV(string arquivo);
};


#endif // BIBLIOTECA_H