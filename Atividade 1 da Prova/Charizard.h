#ifndef CHARIZARD_H
#define CHARIZARD_H

#include "FirePokemon.h"
#include "FlyingPokemon.h"
#include "PokemonState.h"

#define CHARIZARD_INDEX 6

class Charizard : public FirePokemon, public FlyingPokemon {
public:
    Charizard(PokemonState state);
    ~Charizard();

    int getEvolutionTargetIndex() override;
    void printInfo() override;
    void burnUP() override;
    void fly() override;
};

#endif
