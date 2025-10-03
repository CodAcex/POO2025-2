#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time
using namespace std;

int main() {
    int numVagas;

    // Entrada de dados com validação
    do {
        cout << "Digite o numero de vagas do estacionamento (5 a 15): ";
        cin >> numVagas;
    } while (numVagas < 5 || numVagas > 15);

    // Criação dinâmica do array de vagas
    int* estacionamento = new int[numVagas];

    // Inicializa todas as vagas como livres (0)
    for (int i = 0; i < numVagas; i++) {
        estacionamento[i] = 0;
    }

    srand(time(0)); // semente aleatória

    cout << "\n=== Iniciando simulacao de 24 horas ===\n" << endl;

    for (int hora = 1; hora <= 24; hora++) {
        cout << "Hora " << hora << ":" << endl;

        // i. Decrementa tempo de permanência dos carros
        for (int i = 0; i < numVagas; i++) {
            if (estacionamento[i] > 0) {
                estacionamento[i]--;
            }
        }

        // ii. Vagas com 0 ficam livres (já feito no decremento)

        // iii. Novo carro tenta entrar
        bool entrou = false;
        for (int i = 0; i < numVagas; i++) {
            if (estacionamento[i] == 0) {
                // Ocupa a vaga com tempo sorteado entre 1 e 5 horas
                estacionamento[i] = rand() % 5 + 1;
                cout << "Novo carro entrou na vaga " << i << " por " << estacionamento[i] << " horas." << endl;
                entrou = true;
                break;
            }
        }

        if (!entrou) {
            cout << "Estacionamento cheio! Carro nao conseguiu entrar." << endl;
        }

        // Imprime estado atual do estacionamento
        cout << "Estado das vagas: ";
        for (int i = 0; i < numVagas; i++) {
            cout << "[" << estacionamento[i] << "] ";
        }
        cout << "\n" << endl;
    }

    // Libera memória
    delete[] estacionamento;

    cout << "=== Simulacao encerrada ===" << endl;

    return 0;
}