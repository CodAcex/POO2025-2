#ifndef CHARMANDER_H
#define CHARMANDER_H

#include "FirePokemon.h"
#include "PokemonState.h"

#define CHARMANDER_INDEX 4
#define CHARMELEON_INDEX 5

class Charmander : public FirePokemon {
public:
    Charmander(PokemonState state);
    ~Charmander();

    int getEvolutionTargetIndex() override;
    void printInfo() override;
    void burnUP() override;
};

#endif
