#include <iostream>
#include <fstream>      
#include <sstream>      
#include <string>       
#include "Usuario.h"   

using namespace std;

#define MAX_USUARIOS 10 
#define MAX_TROCAS 50
#define MAX_FIGURINHAS_MESTRE 100

void salvarDados(Usuario usuarios[], int nroUsuarios, Troca trocasPendentes[], int nroTrocas);
void carregarFigurinhasMestre(Figurinha figurinhasMestre[], int& nroFigurinhasMestre);
void carregarDados(Usuario usuarios[], int& nroUsuarios, Troca trocasPendentes[], int& nroTrocas);

void exibirMenuPrincipal(Usuario usuarios[], int& nroUsuarios, Usuario*& usuarioLogado, Troca trocasPendentes[], int& nroTrocas);
void exibirMenuColecao(Album& album, string nomeUsuario, Troca trocasPendentes[], int& nroTrocas, Usuario usuarios[], int nroUsuarios);
void exibirMenuAlbum(Usuario& usuario, Troca trocasPendentes[], int& nroTrocas, Figurinha figurinhasMestre[], int nroFigurinhasMestre, Usuario usuarios[], int nroUsuarios);

//Implementa A Persistencia 
void carregarFigurinhasMestre(Figurinha figurinhasMestre[], int& nroFigurinhasMestre) 
{
    cout << "Carregando catalogo a partir de 'figurinhas.csv'..." << endl;
    
    ifstream arquivoFigurinhas("figurinhas.csv");
    string linha;
    nroFigurinhasMestre = 0;
    
    if (arquivoFigurinhas.is_open()) 
    {
        getline(arquivoFigurinhas, linha); 
        while (getline(arquivoFigurinhas, linha) && nroFigurinhasMestre < MAX_FIGURINHAS_MESTRE) 
        {
            stringstream ss(linha);
            string nroStr, nome, time;
            if (getline(ss, nroStr, ',') && getline(ss, nome, ',') && getline(ss, time)) 
            {
                
                int nro = 0;
                stringstream ss_nro(nroStr);
                
                if (!(ss_nro >> nro)) 
                {
                    cout << "Erro em 'figurinhas.csv': " << nroStr << endl;
                    continue; 
                }
                
                Figurinha novaF(nro, nome, time);
                figurinhasMestre[nroFigurinhasMestre++] = novaF;
            }
        }
        arquivoFigurinhas.close();
        cout << "Catalogo mestre carregado. (" << nroFigurinhasMestre << " figurinhas encontradas)" << endl;
    } 
    else 
    {
        cout << "ERRO: Nao foi possivel abrir 'figurinhas.csv'." << endl;
    }
}

Usuario* encontrarUsuario(Usuario usuarios[], int nroUsuarios, string nome) 
{
    for (int i = 0; i < nroUsuarios; ++i) 
    {
        if (usuarios[i].getNomeDeUsuario() == nome) 
        {
            return &usuarios[i];
        }
    }
    return nullptr;
}

void carregarDados(Usuario usuarios[], int& nroUsuarios, Troca trocasPendentes[], int& nroTrocas) 
{
    cout << "Carregando dados do sistema a partir de arquivos separados..." << endl;
    
    ifstream arquivoUsuarios("usuarios.csv");
    string linha;
    nroUsuarios = 0;
    
    if (arquivoUsuarios.is_open()) 
    {
        getline(arquivoUsuarios, linha); 
        while (getline(arquivoUsuarios, linha) && nroUsuarios < MAX_USUARIOS) 
        {
            stringstream ss(linha);
            string nome, senha;
            
            if (getline(ss, nome, ',') && getline(ss, senha)) 
            {
                usuarios[nroUsuarios].cadastrar(nome, senha);
                nroUsuarios++;
            }
        }
        arquivoUsuarios.close();
        cout << "Arquivo fechado com sucesso!" << endl;
    } 
    else 
    {
        cout << "Aviso: Nao foi possivel abrir 'usuarios.csv'. Iniciando sem usuarios salvos." << endl;
    }

    for (int i = 0; i < nroUsuarios; i++) 
    {
        usuarios[i].getAlbum().carregar(usuarios[i].getNomeDeUsuario());
    }

    //Carrega as trocas pendentes
    ifstream arquivoTrocas("trocas.csv");
    nroTrocas = 0;
    if (arquivoTrocas.is_open()) 
    {
        getline(arquivoTrocas, linha); 
        while (getline(arquivoTrocas, linha) && nroTrocas < MAX_TROCAS) 
        {
            stringstream ss(linha);
            string proponente, reqStr, dispStr, statusStr;
            
            if (getline(ss, proponente, ',') && getline(ss, reqStr, ',') && getline(ss, dispStr, ',') && getline(ss, statusStr)) 
            {
                int requerida = 0;
                int disponivel = 0;
                int statusLido = 0;
                
                stringstream ss_req(reqStr);
                stringstream ss_disp(dispStr);
                stringstream ss_status(statusStr);
                
                if (!(ss_req >> requerida) || !(ss_disp >> disponivel) || !(ss_status >> statusLido)) 
                {
                    cout << "Erro de formato (Nro/Status) em 'trocas.csv': " << linha << endl;
                    continue; 
                }

                Troca novaTroca(proponente, requerida, disponivel);
                if (statusLido != 0) 
                {
                    novaTroca.aceitar(statusLido == 1);
                }
                
                trocasPendentes[nroTrocas++] = novaTroca;
            }
        }
        arquivoTrocas.close();
        cout << "Arquivo fechado com sucesso!" << endl;
    }
    
    cout << "Dados carregados. (" << nroUsuarios << " usuarios e " << nroTrocas << " trocas encontradas)" << endl;
}

void salvarDados(Usuario usuarios[], int nroUsuarios, Troca trocasPendentes[], int nroTrocas) 
{
    cout << "Salvando dados do sistema em arquivos separados..." << endl;
    
    ofstream arquivoUsuarios("usuarios.csv");
    if (arquivoUsuarios.is_open()) 
    {
        arquivoUsuarios << "NomeDeUsuario,Senha" << endl; 
        
        for (int i = 0; i < nroUsuarios; i++) 
        {
            arquivoUsuarios << usuarios[i].getNomeDeUsuario() << "," << usuarios[i].getSenha() << endl;
            
            usuarios[i].getAlbum().salvar(usuarios[i].getNomeDeUsuario());
        }
        arquivoUsuarios.close();
        cout << "Usuarios salvos em 'usuarios.csv' e albuns em '[nome]_album.csv'." << endl;
    }

    ofstream arquivoTrocas("trocas.csv");
    if (arquivoTrocas.is_open()) 
    {
        arquivoTrocas << "NomeProponente,FigurinhaRequerida,FigurinhaDisponivel,Status" << endl;
        for (int i = 0; i < nroTrocas; i++) 
        {
            arquivoTrocas << trocasPendentes[i].getNomeProponente() << "," << trocasPendentes[i].getFigurinhaRequerida() << "," << trocasPendentes[i].getFigurinhaDisponivel() << "," << trocasPendentes[i].getStatus() << endl;
        }
        arquivoTrocas.close();
        cout << "Trocas salvas em 'trocas.csv'." << endl;
    }
    
    cout << "=> Dados salvos com sucesso!" << endl;
}

//Implementação do menu principal
void exibirMenuPrincipal(Usuario usuarios[], int& nroUsuarios, Usuario*& usuarioLogado, Troca trocasPendentes[], int& nroTrocas) 
{
    int opcao;
    
    while (usuarioLogado == nullptr) 
    {
        cout << "\n--- Tela Inicial ---" << endl;
        cout << "1. Novo Album (Cadastrar Usuario)" << endl;
        cout << "2. Acessar Album (Login)" << endl;
        cout << "3. Sair do Aplicativo" << endl;
        cout << "Escolha uma opcao: ";
        
        if (!(cin >> opcao)) 
        {
            cout << "Entrada invalida. Digite um numero de opcao (1, 2 ou 3)." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (opcao == 1) 
        {
            if (nroUsuarios < MAX_USUARIOS) 
            {
                string nome, senha;
                cout << "Nome de Usuario: "; 
                cin >> nome;
                cout << "Senha: "; 
                cin >> senha;
                usuarios[nroUsuarios].cadastrar(nome, senha);
                
                nroUsuarios++;
                cout << "Usuario cadastrado! Faca login." << endl;
            } 
        } 
        else if (opcao == 2) 
        {
            string nome, senha;
            cout << "Nome de Usuario: "; 
            cin >> nome;
            cout << "Senha: "; 
            cin >> senha;
            for (int i = 0; i < nroUsuarios; ++i) 
            {
                if (usuarios[i].verificarLogin(nome, senha)) 
                {
                    usuarioLogado = &usuarios[i]; 
                    cout << "Login bem-sucedido. Bem-vindo, " << nome << "!" << endl;
                    return; 
                }
            }
            cout << "Erro: Nome de usuario ou senha invalidos." << endl;
        } 
        else if (opcao == 3) 
        {
            salvarDados(usuarios, nroUsuarios, trocasPendentes, nroTrocas);
            exit(0);
        } 
        else 
        {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }
}

void exibirMenuColecao(Album& album, string nomeUsuario, Troca trocasPendentes[], int& nroTrocas, Usuario usuarios[], int nroUsuarios) 
{
    int opcao, nro;
    
    do {
        cout << "\n--- Tela Gerenciar Colecao ---" << endl;
        album.listarFigurinhasDisponiveis(); 
        album.listarFigurinhasColecionaveis(); 
        cout << "1. Colar Figurinha" << endl;
        cout << "2. Disponibilizar para Troca" << endl;
        cout << "3. Propor Troca de Figurinhas" << endl; 
        cout << "4. Revisar Solicitacoes de Troca" << endl;
        cout << "5. Voltar ao menu Anterior" << endl;
        cout << "Escolha uma opcao: ";
        
        if (!(cin >> opcao)) 
        { 
            cout << "Entrada invalida. Digite um numero de opcao." << endl;
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            continue; 
        }

        if (opcao == 1)
        {
            cout << "Numero da figurinha a ser colada: ";
            if (!(cin >> nro)) 
            { 
                cin.clear(); 
                cin.ignore(10000, '\n'); 
                continue;
            }
            album.colarFigurinha(nro);
        } 
        else if (opcao == 2) 
        {
            cout << "Numero da figurinha a disponibilizar para troca: ";
            if (!(cin >> nro)) 
            { 
                cin.clear(); 
                cin.ignore(10000, '\n'); 
                continue; 
            }
            album.disponibilizarParaTroca(nro);
        } 
        else if (opcao == 3) 
        {
            
             if (nroTrocas >= MAX_TROCAS) 
            {
            cout << "Erro: Limite maximo de trocas pendentes atingido." << endl;
            continue;
            }
    
        cout << "\n--- LISTA DE USUARIOS DISPONIVEIS ---" << endl;
            for (int i = 0; i < nroUsuarios; ++i) 
            { 
                if (usuarios[i].getNomeDeUsuario() != nomeUsuario) 
                 {
                cout << i + 1 << ". " << usuarios[i].getNomeDeUsuario() << " - Figurinhas disponiveis: ";
                usuarios[i].getAlbum().listarFigurinhasDisponiveis(); 
                cout << endl;
                }
    }

    string parceiroNome;
        cout << "Nome do Parceiro de Troca: "; cin >> parceiroNome;

        Usuario* parceiro = encontrarUsuario(usuarios, nroUsuarios, parceiroNome);
        if (parceiro == nullptr || parceiro->getNomeDeUsuario() == nomeUsuario) 
        {
        cout << "ERRO: Parceiro de troca invalido ou nao encontrado." << endl;
        continue;
        }

        // Logica da troca.
        int figRequerida, figDisponivel;
        cout << "\n--- Propor Nova Troca com " << parceiroNome << " ---" << endl;
        cout << "Figurinha que voce quer receber (Nro): ";
        if (!(cin >> figRequerida)) 
        { 
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            continue; 
        }
    
        cout << "Figurinha que voce DISPONIBILIZA (Nro): ";
        if (!(cin >> figDisponivel)) 
        { 
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            continue; 
        }

        if (album.encontrarFigurinha(figDisponivel, FIG_PARA_TROCA) != nullptr) 
        {
        Troca novaTroca(nomeUsuario, figRequerida, figDisponivel);
        trocasPendentes[nroTrocas++] = novaTroca;    
        parceiro->getAlbum().adicionarTroca(novaTroca); 
        cout << "Proposta de troca enviada para " << parceiroNome << " com sucesso! Aguardando aceite." << endl;
        } 
        else 
        {
        cout << "Erro: Voce deve possuir a figurinha #" << figDisponivel << " e ela deve estar marcada como 'DISPONIVEL PARA TROCA' (Status 2)." << endl;
        }

        } 
        else if (opcao == 4) 
        {
            album.revisarSolicitacoes(); 
        } 
        else if (opcao == 5) 
        {
            break; 
        } 
        else 
        {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (true);
}

void exibirMenuAlbum(Usuario &usuario, Troca trocasPendentes[], int &nroTrocas, Figurinha figurinhasMestre[], int nroFigurinhasMestre, Usuario usuarios[], int nroUsuarios)
{
    int opcao;
    Album& album = usuario.getAlbum(); 
    
    do 
    {
        cout << "\n--- Tela Gerenciar Album de " << usuario.getNomeDeUsuario() << " ---" << endl;
        cout << "1. Ver Album (Capas/Paginas)" << endl;
        cout << "2. Gerenciar a Colecao (Colar/Troca)" << endl;
        cout << "3. Abrir pacote de Figurinha (3 novas)" << endl;
        cout << "4. Voltar ao menu Anterior (Logout)" << endl;
        cout << "Escolha uma opcao: ";
        
        if (!(cin >> opcao)) 
        {
            cout << "Entrada invalida. Digite um numero de opcao." << endl;
            cin.clear(); cin.ignore(10000, '\n'); continue;
        }

        if (opcao == 1) 
        {
            album.getPagina(1).listar(); 
            album.getPagina(2).listar();
            album.getPagina(3).listar();
            album.getPagina(4).listar();
            album.getPagina(5).listar();
        } 
        else if (opcao == 2) 
        {
            exibirMenuColecao(album, usuario.getNomeDeUsuario(), trocasPendentes, nroTrocas, usuarios, nroUsuarios); 
        } 
        else if (opcao == 3) 
        {
            album.abrirPacote(figurinhasMestre, nroFigurinhasMestre);
        } 
        else if (opcao == 4) 
        {
            cout << "Voltando ao Menu Principal..." << endl;
            break; 
        } 
        else 
        {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (true);
}


int main() 
{
    Figurinha figurinhasMestre[MAX_FIGURINHAS_MESTRE];
    int nroFigurinhasMestre = 0;                    
    Usuario usuarios[MAX_USUARIOS];
    int nroUsuarios = 0; 
    Troca trocasPendentes[MAX_TROCAS];
    int nroTrocas = 0;
    
    Usuario* usuarioLogado = nullptr; 

    carregarFigurinhasMestre(figurinhasMestre, nroFigurinhasMestre); 
    carregarDados(usuarios, nroUsuarios, trocasPendentes, nroTrocas);
    
    while (true) 
    {
        if (usuarioLogado == nullptr) 
        {
            exibirMenuPrincipal(usuarios, nroUsuarios, usuarioLogado, trocasPendentes, nroTrocas);
        } 
        else 
        {
            exibirMenuAlbum(*usuarioLogado, trocasPendentes, nroTrocas, figurinhasMestre, nroFigurinhasMestre,usuarios, nroUsuarios);
            usuarioLogado = nullptr;
        }
    }
    
    return 0;
}
