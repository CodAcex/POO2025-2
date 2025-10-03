#include "Dado.h"
#include <iostream>
using namespace std;

int main() {
    srand(time(0)); // semente aleatória

    // a) Ponteiro para objeto Dado com 6 faces
    Dado* d1 = new Dado(6);
    cout << "Dado com " << d1->getFaces() << " faces rolou: " << d1->rolar() << endl;

    delete d1; // libera memória

    cout << "\n--- Array dinamico de dados ---\n" << endl;

    // b) Array dinâmico de 3 dados
    Dado* dados = new Dado[3];

    dados[0].setFaces(6);
    dados[1].setFaces(8);
    dados[2].setFaces(12);

    for (int i = 0; i < 3; i++) {
        cout << "Dado " << (i+1) << " (" << dados[i].getFaces() << " faces): ";
        for (int j = 0; j < 3; j++) {
            cout << dados[i].rolar() << " ";
        }
        cout << endl;
    }

    delete[] dados; // libera memória

    return 0;
}