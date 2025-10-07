#include "Album.h"
#include <iostream> 
#include <cstdlib> 
#include <ctime>   
#include <string>
#include <fstream>   
#include <sstream>   

using namespace std;

// ======================================================================
// Auxiliares
// ======================================================================

Figurinha* Album::encontrarFigurinha(int nro, int statusDesejado) {
    for (int i = 0; i < this->quantidade; i++) {
        if (this->figurinhas[i].getNro() == nro && 
            (statusDesejado == -1 || this->figurinhas[i].getStatus() == statusDesejado)) {
            return &this->figurinhas[i];
        }
    }
    return nullptr;
}

Pagina* Album::encontrarPagina(int nroFigurinha) {
    for (int i = 0; i < this->nroPaginas; ++i) {
        if (nroFigurinha >= this->paginas[i].getNroInicial() && 
            nroFigurinha <= this->paginas[i].getNroFinal()) {
            return &this->paginas[i];
        }
    }
    return nullptr;
}

void Album::inicializarPaginas() {
    if (this->nroPaginas < 20) {
        this->paginas[0] = Pagina("FASE DE GRUPOS 1", 1, 10);
        this->paginas[1] = Pagina("FASE DE GRUPOS 2", 11, 20);
        this->nroPaginas = 2;
    }
}

// Construtor
Album::Album()
{
    this->quantidade = 0;
    this->nroTrocas = 0;
    this->nroPaginas = 0;
    inicializarPaginas(); 
    srand(time(0)); 
}

// Destrutor
Album::~Album() {}

// ======================================================================
// Métodos de Lógica
// ======================================================================

void Album::adicionar(Figurinha f) { 
    if (this->quantidade < 100) { 
        this->figurinhas[this->quantidade] = f;
        this->quantidade++;
    }
}

bool Album::possui(int nro) { 
    return this->encontrarFigurinha(nro, -1) != nullptr;
}

void Album::colarFigurinha(int nro) {
    Figurinha* f = this->encontrarFigurinha(nro, 0); 
    
    if (f == nullptr) {
        cout << "ERRO: Figurinha #" << nro << " nao encontrada como repetida (Status 0)." << endl;
        return;
    }

    f->setStatus(1); // 1: Colada
    
    Pagina* paginaAlvo = this->encontrarPagina(f->getNro());
    if (paginaAlvo != nullptr) {
        paginaAlvo->adicionarFigurinha(*f); 
        cout << "Figurinha #" << nro << " Colada com sucesso (Status 1)!" << endl;
    } else {
        cout << "Aviso: Figurinha colada, mas a pagina nao foi encontrada para exibicao." << endl;
    }
}

void Album::disponibilizarParaTroca(int nro) {
    Figurinha* f = this->encontrarFigurinha(nro, 0); 
    
    if (f != nullptr) {
        f->setStatus(2); // 2: Disponível para Troca
        cout << "Figurinha #" << nro << " AGORA esta DISPONIVEL para troca (Status 2)." << endl;
    } else {
        cout << "ERRO: Figurinha #" << nro << " nao encontrada como repetida (Status 0)." << endl;
        cout << "Ela deve ser repetida (0) para ser colocada para troca." << endl;
    }
}

void Album::abrirPacote() {
    cout << "\n--- Abrindo Pacote de 3 Figurinhas ---" << endl;
    
    for (int i = 0; i < 3; ++i) {
        int nroAleatorio = (rand() % 20) + 1; 

        string nroStr = to_string(nroAleatorio);
        Figurinha novaFig(nroAleatorio, "Jogador #" + nroStr, "Time de " + nroStr);
        
        novaFig.setStatus(0); 
        
        this->adicionar(novaFig);
        
        cout << "  - Nova Figurinha obtida: #" << nroAleatorio << endl;
    }
    cout << "---------------------------------------" << endl;
    cout << "Total de figurinhas na colecao: " << this->quantidade << endl; 
}

void Album::listarFigurinhasDisponiveis() { 
    cout << "\nFigurinhas Disponiveis para Troca (Status 2):" << endl;
    bool encontrou = false;
    
    for (int i = 0; i < this->quantidade; i++) {
        if (this->figurinhas[i].getStatus() == 2) { 
            cout << "[#] #" << this->figurinhas[i].getNro() << " - " 
                 << this->figurinhas[i].getNome() << " (" << this->figurinhas[i].getTime() << ")" << endl;
            encontrou = true;
        }
    }
    if (!encontrou) {
        cout << "Nenhuma figurinha disponivel para troca no momento." << endl;
    }
}
void Album::listarFigurinhasColecionaveis() { 
    cout << "\nFigurinhas Repetidas/Troca (Status 0 e 2):" << endl;
    bool encontrou = false;
    
    for (int i = 0; i < this->quantidade; i++) {
        int status = this->figurinhas[i].getStatus();
        
        // Verifica Status 0 (Repetida) OU Status 2 (Marcada para Troca)
        if (status == 0 || status == 2) { 
            cout << "[#" << this->figurinhas[i].getNro() << "] - " 
                 << this->figurinhas[i].getNome() << " (Status: " << status << ")" << endl;
            encontrou = true;
        }
    }
    if (!encontrou) {
        cout << "Nenhuma figurinha disponivel para uso (colar/trocar) no momento." << endl;
    }
}

Pagina& Album::getPagina(int index) {
    return this->paginas[index-1];
}

void Album::revisarSolicitacoes() {
    cout << "Revisando solicitacoes de troca (a implementar)." << endl;
}

// ======================================================================
// RESTAURADO: Album::salvar() (Cria [nome]_album.csv)
// ======================================================================
void Album::salvar(string nomeUsuario) 
{
    string nomeArquivo = nomeUsuario + "_album.csv";
    ofstream arquivo(nomeArquivo);
    
    if (arquivo.is_open()) {
        arquivo << "Nro,Status" << endl; 
        
        for (int i = 0; i < this->quantidade; i++) {
            Figurinha& f = this->figurinhas[i];
            arquivo << f.getNro() << "," 
                    << f.getStatus() << endl; 
        }
        arquivo.close();
        // Não imprime mensagem de sucesso aqui para evitar poluir o console na chamada global
    } else {
        cout << "ERRO: Nao foi possivel salvar o album de " << nomeUsuario << "." << endl; 
    }
}

// ======================================================================
// RESTAURADO: Album::carregar() (Le [nome]_album.csv)
// ======================================================================
void Album::carregar(string nomeUsuario) 
{
    string nomeArquivo = nomeUsuario + "_album.csv";
    ifstream arquivo(nomeArquivo);
    string linha;
    
    this->quantidade = 0;
    this->inicializarPaginas(); 

    if (arquivo.is_open()) {
        getline(arquivo, linha); // Pula cabeçalho
        
        while (getline(arquivo, linha) && this->quantidade < 100) {
            stringstream ss(linha);
            string nroStr, statusStr;

            if (getline(ss, nroStr, ',') && getline(ss, statusStr)) {
                
                int nro = 0; 
                int status = 0;
                
                stringstream ss_nro(nroStr);
                stringstream ss_status(statusStr);
                if (!(ss_nro >> nro) || !(ss_status >> status)) {
                    // cout << "Erro de formato em arquivo de album: " << linha << endl; 
                    continue; 
                }
                
                Figurinha f(nro, "Jogador #" + nroStr, "Time de " + nroStr); 
                f.setStatus(status);
                
                this->figurinhas[this->quantidade] = f;
                this->quantidade++;

                // Adicionar figurinha à página SOMENTE SE o status for COLADA (1)
                if (status == 1) { 
                    Pagina* paginaAlvo = this->encontrarPagina(f.getNro());
                    if (paginaAlvo != nullptr) {
                        paginaAlvo->adicionarFigurinha(f); 
                    }
                }
            }
        }
        arquivo.close();
        // Não imprime mensagem de sucesso aqui para evitar poluir o console na chamada global
    } else {
        // Arquivo não encontrado, Album vazio é criado pelo construtor. OK.
    }
}