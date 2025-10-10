#include "Album.h"
#include <iostream> 
#include <cstdlib> 
#include <ctime>   
#include <string>
#include <fstream>   
#include <sstream>   

using namespace std;

Figurinha* Album::encontrarFigurinha(int nro, int statusDesejado) 
{
    for (int i = 0; i < this->quantidade; i++) 
    {
        if (this->figurinhas[i].getNro() == nro && (statusDesejado == -1 || this->figurinhas[i].getStatus() == statusDesejado)) 
            {
            return &this->figurinhas[i];
            }
    }
    return nullptr;
}

Pagina* Album::encontrarPagina(int nroFigurinha) 
{
    for (int i = 0; i < this->nroPaginas; ++i) 
    {
        if (nroFigurinha >= this->paginas[i].getNroInicial() && nroFigurinha <= this->paginas[i].getNroFinal()) 
        {
            return &this->paginas[i];
        }
    }
    return nullptr;
}

void Album::inicializarPaginas() 
{
    if (this->nroPaginas < 5) 
    {
        this->paginas[0] = Pagina("FASE DE GRUPOS 1", 1, 20);
        this->paginas[1] = Pagina("FASE DE GRUPOS 2", 21, 40);
        this->paginas[2] = Pagina("FASE DE GRUPOS 3", 41, 60);
        this->paginas[3] = Pagina("FASE DE GRUPOS 4", 61, 80);
        this->paginas[4] = Pagina("FASE DE GRUPOS 5", 81, 100);
        this->nroPaginas = 5;
    }
}


Album::Album()
{
    this->quantidade = 0;
    this->nroTrocas = 0;
    this->nroPaginas = 0;
    inicializarPaginas(); 
    srand(time(0)); 
}


Album::~Album() 
{

}

void Album::adicionar(Figurinha f) 
{ 
    if (this->quantidade < 100) 
    { 
        this->figurinhas[this->quantidade] = f;
        this->quantidade++;
    }
}

bool Album::possui(int nro) 
{ 
    return this->encontrarFigurinha(nro, -1) != nullptr;
}

void Album::colarFigurinha(int nro) 
{
    Figurinha* f = this->encontrarFigurinha(nro, 0); 
    
    if (f == nullptr) 
    {
        cout << "ERRO: Figurinha #" << nro << " nao encontrada como repetida (Status 0)." << endl;
        return;
    }

    f->setStatus(1); // 1: Colada
    
    Pagina* paginaAlvo = this->encontrarPagina(f->getNro());
    if (paginaAlvo != nullptr) 
    {
        paginaAlvo->adicionarFigurinha(*f); 
        cout << "Figurinha #" << nro << " Colada com sucesso (Status 1)!" << endl;
    } else 
    {
        cout << "Aviso: Figurinha colada, mas a pagina nao foi encontrada para exibicao." << endl;
    }
}

void Album::disponibilizarParaTroca(int nro) 
{
    Figurinha* f = this->encontrarFigurinha(nro, 0); 
    
    if (f != nullptr) 
    {
        f->setStatus(2); // 2: Disponível para Troca
        cout << "Figurinha #" << nro << " AGORA esta DISPONIVEL para troca (Status 2)." << endl;
    } else 
    {
        cout << "ERRO: Figurinha #" << nro << " nao encontrada como repetida (Status 0)." << endl;
        cout << "Ela deve ser repetida (0) para ser colocada para troca." << endl;
    }
}

void Album::abrirPacote(Figurinha figurinhasMestre[], int nroFigurinhasMestre) 
{
    cout << "\n--- Abrindo Pacote de 3 Figurinhas ---" << endl;
    
    int limite; 

if (nroFigurinhasMestre > 0)
{
    limite = nroFigurinhasMestre;
} 
else
{
    limite = 20;
}

    for (int i = 0; i < 3; ++i) 
    {
        int nroAleatorio = (rand() % limite) + 1; 
      
        Figurinha figurinhaMestraEncontrada; 
        bool encontrada = false;

        for (int j = 0; j < nroFigurinhasMestre; ++j) 
        {
            if (figurinhasMestre[j].getNro() == nroAleatorio) 
            {
                figurinhaMestraEncontrada = figurinhasMestre[j];
                encontrada = true;
                break;
            }
        }
        
        if (encontrada)
        {
            Figurinha novaFig(figurinhaMestraEncontrada.getNro(), figurinhaMestraEncontrada.getNome(), figurinhaMestraEncontrada.getTime());
            
            novaFig.setStatus(0); 
            this->adicionar(novaFig);
            
            cout << "  - Nova Figurinha obtida: #" << novaFig.getNro() << " - " << novaFig.getNome() << " (" << novaFig.getTime() << ")" << endl;
        } 
        else 
        {
            cout << "  - ERRO: Figurinha #" << nroAleatorio << " gerada, mas nao encontrada no catalogo mestre." << endl;
        }
    }
    cout << "---------------------------------------" << endl;
}

void Album::listarFigurinhasDisponiveis() 
{ 
    cout << "\nFigurinhas Disponiveis para Troca (Status 2):" << endl;
    bool encontrou = false;
    
    for (int i = 0; i < this->quantidade; i++) 
    {
        if (this->figurinhas[i].getStatus() == 2) 
        { 
            cout << "[#] #" << this->figurinhas[i].getNro() << " - " << this->figurinhas[i].getNome() << " (" << this->figurinhas[i].getTime() << ")" << endl;
            encontrou = true;
        }
    }
    if (!encontrou) 
    {
        cout << "Nenhuma figurinha disponivel para troca no momento." << endl;
    }
}
void Album::listarFigurinhasColecionaveis() 
{ 
    cout << "\nFigurinhas Repetidas/Troca (Status 0 e 2):" << endl;
    bool encontrou = false;
    
    for (int i = 0; i < this->quantidade; i++) 
    {
        int status = this->figurinhas[i].getStatus();
        
        if (status == FIG_NA_COLECAO || status == FIG_PARA_TROCA) 
        { 
            cout << "[#" << this->figurinhas[i].getNro() << "] - " << this->figurinhas[i].getNome() << " (" << this->figurinhas[i].getNomeStatus() << ")" << endl; // <--- MUDANÇA AQUI
            encontrou = true;
        }
    }
    if (!encontrou) 
    {
        cout << "Nenhuma figurinha disponivel para uso (colar/trocar) no momento." << endl;
    }
}

Pagina& Album::getPagina(int i) 
{
    return this->paginas[i-1];
}

void Album::revisarSolicitacoes() 
{
    if (this->nroTrocas == 0) 
    {
        cout << "Nenhuma solicitacao de troca pendente para voce." << endl;
        return;
    }

    cout << "\n--- REVISAR SOLICITACOES DE TROCA PENDENTES ---" << endl;
    
    for (int i = 0; i < this->nroTrocas; ++i) 
    {
        if (this->trocas[i].getStatus() == TROCA_AGUARDANDO) 
        {
            cout << " [" << i + 1 << "] Proposta de " << this->trocas[i].getNomeProponente() << ": Voce RECEBE #" << this->trocas[i].getFigurinhaDisponivel() << " por sua #" << this->trocas[i].getFigurinhaRequerida() << endl;
        }
    }
    
    int indice, acao;
    cout << "Digite o Nro da Proposta para Revisar (1-" << this->nroTrocas << ") ou 0 para Sair: ";
    if (!(cin >> indice) || indice < 0 || indice > this->nroTrocas) 
    { 
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        return; 
    }

    if (indice == 0) return;
    
    Troca& troca = this->trocas[indice - 1];

    if (troca.getStatus() != TROCA_AGUARDANDO) 
    {
        cout << "Esta troca ja foi " << (troca.getStatus() == TROCA_ACEITA ? "ACEITA" : "RECUSADA") << "." << endl;
        return;
    }

    cout << "Acao para Proposta #" << indice << " (1-Aceitar, 2-Recusar): ";
    if (!(cin >> acao) || (acao != 1 && acao != 2)) 
    { 
        cout << "Acao invalida." << endl; cin.clear(); cin.ignore(10000, '\n'); return; 
    }

    if (acao == 1) 
    {
        
        if (this->encontrarFigurinha(troca.getFigurinhaRequerida(), FIG_PARA_TROCA) != nullptr) 
        {
            troca.aceitar(true);
            cout << "Troca ACEITA." << endl;      
        } 
        else 
        {
            cout << "ERRO: Voce nao tem a figurinha #" << troca.getFigurinhaRequerida() << " disponivel para troca (Status 2)." << endl;
            troca.aceitar(false);
        }
    } else {
        troca.aceitar(false);
        cout << "Troca RECUSADA." << endl;
    }
}

void Album::salvar(string nomeUsuario) 
{
    string nomeArquivo = nomeUsuario + "_album.csv";
    ofstream arquivo(nomeArquivo);
    
    if (arquivo.is_open()) 
    {
        arquivo << "Nro,Status" << endl; 
        
        for (int i = 0; i < this->quantidade; i++)
        {
            Figurinha& f = this->figurinhas[i];
            arquivo << f.getNro() << "," << f.getStatus() << endl; 
        }
        arquivo.close();
        cout << "Arquivo fechado com sucesso!" << endl;
    } 
    else 
    {

        cout << "ERRO: Nao foi possivel salvar o album de " << nomeUsuario << "." << endl; 
    }
}

void Album::carregar(string nomeUsuario) 
{
    string nomeArquivo = nomeUsuario + "_album.csv";
    ifstream arquivo(nomeArquivo);
    string linha;
    
    this->quantidade = 0;
    this->inicializarPaginas(); 

    if (arquivo.is_open()) 
    {
        getline(arquivo, linha); // Pula cabeçalho
        
        while (getline(arquivo, linha) && this->quantidade < 100) 
        {
            stringstream ss(linha);
            string nroStr, statusStr;

            if (getline(ss, nroStr, ',') && getline(ss, statusStr)) 
            {
                
                int nro = 0; 
                int status = 0;
                
                stringstream ss_nro(nroStr);
                stringstream ss_status(statusStr);
                if (!(ss_nro >> nro) || !(ss_status >> status)) 
                {
                    cout << "Erro de formato em arquivo de album: " << linha << endl; 
                    continue; 
                }
                
                Figurinha f(nro, "Jogador #" + nroStr, "Time de " + nroStr); 
                f.setStatus(status);
                
                this->figurinhas[this->quantidade] = f;
                this->quantidade++;

                if (status == 1) 
                { 
                    Pagina* paginaAlvo = this->encontrarPagina(f.getNro());
                    if (paginaAlvo != nullptr) 
                    {
                        paginaAlvo->adicionarFigurinha(f); 
                    }
                }
            }
        }
        arquivo.close();
        cout << "Arquivo fechado com sucesso!" << endl;
    } 
    else 
    {
        cout << "Arquivo não encontrado!" << endl;
    }
}

void Album::adicionarTroca(Troca t)
{
    if (this->nroTrocas < 10) 
    {
        this->trocas[this->nroTrocas++] = t;
    } 
    else 
    {
        cout << "Aviso: Limite de solicitacoes de troca recebidas atingido." << endl;
    }
}
