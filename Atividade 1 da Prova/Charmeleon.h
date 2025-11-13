#ifndef CHARMELEON_H
#define CHARMELEON_H

#include "FirePokemon.h"
#include "PokemonState.h"

#define CHARMELEON_INDEX 5
#define CHARIZARD_INDEX 6

class Charmeleon : public FirePokemon {
public:
    Charmeleon(PokemonState state);
    ~Charmeleon();

    int getEvolutionTargetIndex() override;
    void burnUP() override;
    void printInfo() override;
};

#endif
