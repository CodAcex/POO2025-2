#include "Dado.h"

Dado::Dado() {
    this->faces = 6; // padrão
}

Dado::Dado(int faces) {
    this->faces = (faces > 0 ? faces : 6);
}

void Dado::setFaces(int faces) {
    this->faces = (faces > 0 ? faces : 6);
}

int Dado::getFaces() {
    return faces;
}

int Dado::rolar() {
    return (rand() % faces) + 1;
}