#include <iostream>
#include "Biblioteca.h"

using namespace std;

static int lerInt(string prompt) 
{
while (true) 
{
cout << prompt;
string s;

if (!getline(cin, s)) 
return 0;

if (s.size() == 0) 
continue;

bool ok = true;

for (size_t i = 0; i < s.size(); ++i) 
{
char c = s[i];

if (c < '0' || c > '9') 
{ 
    ok = false; break; 
}
}
if (ok) return stoi(s);
cout << "Entrada invalida";
}

}


static string lerLinha(string prompt) 
{
cout << prompt;
string s;
getline(cin, s);
return s;
}


int main() 
{
Biblioteca bib;


// adicionar itens iniciais para demonstracao
bib.adicionar(new Livro(bib.gerarId(), "Clean Code", 2008, "Robert C. Martin", 464)); cout << "\n";
bib.adicionar(new LivroRaro(bib.gerarId(), "Antigo Exemplo", 1920, "Autor X", 200, "fragil")); cout << "\n";
bib.adicionar(new Revista(bib.gerarId(), "Science Today", 2021, 42, "mensal")); cout << "\n";
bib.adicionar(new MidiaDigital(bib.gerarId(), "Album Top", 2015, "mp3")); cout << "\n";
bib.adicionar(new DVDItem(bib.gerarId(), "Inception", 2010, "mp4", "Region 1")); cout << "\n";


bool rodando = true;

while (rodando) 
{
cout << "\n";
cout << "--- MENU ---" << endl;
cout << "1. Listar itens" << endl;
cout << "2. Adicionar Livro" << endl;
cout << "3. Adicionar Livro Raro"<< endl;
cout << "4. Adicionar Revista"<< endl;
cout << "5. Adicionar Midia Digital"<< endl;
cout << "6. Adicionar DVD"<< endl;
cout << "7. Emprestar (por ID)"<< endl;
cout << "8. Devolver (por ID)"<< endl;
cout << "9. Calcular taxa de atraso (por ID)"<< endl;
cout << "10. Salvar CSV"<< endl;
cout << "11. Carregar CSV"<< endl;
cout << "0. Sair"<< endl;


int opc = lerInt("Opc: ");
if (opc == 0) 
{ 
    rodando = false; break; 
}

if (opc == 1)
 { 
    bib.listarTodos();
    continue; 
}

if (opc == 2) 
{
string titulo = lerLinha("Titulo: ");
int ano = lerInt("Ano: ");
string autor = lerLinha("Autor: ");
int pag = lerInt("Paginas: ");
bib.adicionar(new Livro(bib.gerarId(), titulo, ano, autor, pag));
continue;
}

if (opc == 3) 
{
string titulo = lerLinha("Titulo: ");
int ano = lerInt("Ano: ");
string autor = lerLinha("Autor: ");
int pag = lerInt("Paginas: ");
string cond = lerLinha("Condicao: ");
bib.adicionar(new LivroRaro(bib.gerarId(), titulo, ano, autor, pag, cond));
continue;
}

if (opc == 4) 
{
string titulo = lerLinha("Titulo: ");
int ano = lerInt("Ano: ");
int ed = lerInt("Edicao: ");
string per = lerLinha("Periodicidade: ");
bib.adicionar(new Revista(bib.gerarId(), titulo, ano, ed, per));
continue;
}

if (opc == 5) 
{
string titulo = lerLinha("Titulo: ");
int ano = lerInt("Ano: ");
string formato = lerLinha("Formato: ");
bib.adicionar(new MidiaDigital(bib.gerarId(), titulo, ano, formato));
continue;
}

if (opc == 6) 
{
string titulo = lerLinha("Titulo: ");
int ano = lerInt("Ano: ");
string formato = lerLinha("Formato: ");
string regiao = lerLinha("Regiao: ");
bib.adicionar(new DVDItem(bib.gerarId(), titulo, ano, formato, regiao));
continue;

}
if (opc == 7) 
{
int id = lerInt("ID: ");
ItemAcervo* it = bib.buscarPorId(id);
if (it == 0) 
cout << "Item nao encontrado";
else 
{ 
    it->emprestar(); cout << "Emprestado"; 
}

continue;
}

if (opc == 8) 
{
int id = lerInt("ID: ");
ItemAcervo* it = bib.buscarPorId(id);
if (it == 0) 
cout << "Item nao encontrado";
else 
{ 
    it->devolver(); cout << "Devolvido"; 
}
continue;
}

if (opc == 9) 
{
int id = lerInt("ID: ");
int dias = lerInt("Dias de atraso: ");
ItemAcervo* it = bib.buscarPorId(id);
if (it == 0) 
cout << "Item nao encontrado";
else 
{
float taxa = it->calcularTaxaAtraso(dias);
cout << "Taxa de atraso: " << taxa << "";
}
continue;
}

if (opc == 10) 
{
string arq = lerLinha("Arquivo (ex: save.csv): ");
if (arq.size() == 0) 
arq = "save.csv";
bib.salvarCSV(arq);
continue;
}

if (opc == 11) 
{
string arq = lerLinha("Arquivo (ex: save.csv): ");
if (arq.size() == 0) arq = "save.csv";
bib.carregarCSV(arq);
continue;
}


cout << "Opcao invalida";
}


cout << "Finalizando...";
return 0;
}