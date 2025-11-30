#include "Biblioteca.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Biblioteca::Biblioteca() 
{ 
    proximoId = 1; 
}


Biblioteca::~Biblioteca() 
{

for (size_t i = 0; i < itens.size(); ++i) 
{
delete itens[i];
}

itens.clear();
}


int Biblioteca::gerarId() 
{ 
    int old = proximoId; proximoId = proximoId + 1; return old; 
}


void Biblioteca::adicionar(ItemAcervo* item) 
{ 
    itens.push_back(item); 
}


ItemAcervo* Biblioteca::buscarPorId(int id) 
{
for (size_t i = 0; i < itens.size(); ++i) 
{
if (itens[i]->getId() == id) return itens[i];
}
return 0;
}


void Biblioteca::listarTodos() 
{
if (itens.size() == 0) 
{
cout << "Biblioteca vazia";
return;

}
for (size_t i = 0; i < itens.size(); ++i) itens[i]->mostrar();
}


bool Biblioteca::removerPorId(int id) 
{

for (size_t i = 0; i < itens.size(); ++i) 
{

if (itens[i]->getId() == id) 

{
delete itens[i]; //delete manual do vector

for (size_t j = i; j + 1 < itens.size(); ++j) 
itens[j] = itens[j + 1];
itens.pop_back();
return true;
}

}
return false;
}

void Biblioteca::salvarCSV(string arquivo) 
{
ofstream out(arquivo.c_str());
if (!out.good()) 
{
cout << "Erro ao abrir arquivo para salvar";
return;
}

for (size_t i = 0; i < itens.size(); ++i) 
{
out << itens[i]->toCSV() << endl;
}
out.close();
}


void Biblioteca::carregarCSV(string arquivo) 
{
ifstream in(arquivo.c_str());
if (!in.good()) 
{
cout << "Arquivo nao encontrado!";
return;
}


// limpa itens atuais
for (size_t i = 0; i < itens.size(); ++i) delete itens[i];
itens.clear();
proximoId = 1;


string line;
while (getline(in, line)) 
{
if (line.size() == 0) continue;
vector<string> parts;
string cur;
istringstream ss(line);

while (getline(ss, cur, ';')) parts.push_back(cur);

if (parts.size() == 0) 
continue;

string tipo = parts[0];


if (tipo == "Livro") 
{
int id = stoi(parts[1]);

string titulo = parts[2];

int ano = stoi(parts[3]);

string autor = parts[4];

int paginas = stoi(parts[5]);

bool emp = parts[6] == "1";

Livro* l = new Livro(id, titulo, ano, autor, paginas);

if (emp) l->emprestar();

itens.push_back(l);

if (id >= proximoId) proximoId = id + 1;

}

else if (tipo == "LivroRaro") 
{

int id = stoi(parts[1]);

string titulo = parts[2];

int ano = stoi(parts[3]);

string autor = parts[4];

int paginas = stoi(parts[5]);

string cond = parts[6];

bool emp = parts[7] == "1";

LivroRaro* lr = new LivroRaro(id, titulo, ano, autor, paginas, cond);

if (emp) lr->emprestar();

itens.push_back(lr);

if (id >= proximoId) proximoId = id + 1;

}

else if (tipo == "Revista") 
{
int id = stoi(parts[1]);

string titulo = parts[2];

int ano = stoi(parts[3]);

int ed = stoi(parts[4]);

string per = parts[5];

bool emp = parts[6] == "1";

Revista* r = new Revista(id, titulo, ano, ed, per);

if (emp) r->emprestar();

itens.push_back(r);

if (id >= proximoId) proximoId = id + 1;
}

else if (tipo == "MidiaDigital") 
{
int id = stoi(parts[1]);

string titulo = parts[2];

int ano = stoi(parts[3]);

string formato = parts[4];

bool emp = parts[5] == "1";

MidiaDigital* m = new MidiaDigital(id, titulo, ano, formato);

if (emp) m->emprestar();

itens.push_back(m);

if (id >= proximoId) proximoId = id + 1;

}

else if (tipo == "DVD") 
{
int id = stoi(parts[1]);

string titulo = parts[2];

int ano = stoi(parts[3]);

string formato = parts[4];

string regiao = parts[5];


bool emp = parts[6] == "1";

DVDItem* d = new DVDItem(id, titulo, ano, formato, regiao);

if (emp) d->emprestar();

itens.push_back(d);

if (id >= proximoId) proximoId = id + 1;
}

}


in.close();
}