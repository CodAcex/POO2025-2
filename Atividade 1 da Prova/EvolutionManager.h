#ifndef EVOLUTION_MANAGER_H
#define EVOLUTION_MANAGER_H

#include "Pokemon.h"
#include "PokemonState.h"

class EvolutionManager {
public:
    Pokemon* capturePokemon(int speciesIndex, PokemonState state);
    Pokemon* evolve(Pokemon* oldPokemon);

private:
    Pokemon* createPokemon(int speciesIndex, PokemonState state);
};

#endif
