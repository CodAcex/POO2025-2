#include "Cachorro.h"
#include "Gato.h"
#include "Galinha.h"

int main()
{
    Cachorro cachorro("TOTOro", "au au");
    cachorro.fazerSom();

    Gato gato("Garfield", "miau");
    gato.fazerSom();

    Galinha galinha("Galinha Pintadinha", "co corico");
    galinha.fazerSom();

    return 0;
}