#define DADO_H

#include <cstdlib>
#include <ctime>

class Dado {
private:
    int faces;

public:
    // Construtor padrão
    Dado();

    // Construtor parametrizado
    Dado(int faces);

    // Setter
    void setFaces(int faces);

    // Getter
    int getFaces();

    // Método principal
    int rolar();
};
