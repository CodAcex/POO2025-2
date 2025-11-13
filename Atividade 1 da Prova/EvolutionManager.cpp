#include "EvolutionManager.h"
#include "Pokemon.h"
#include "Charmander.h"
#include "Charmeleon.h"
#include "Charizard.h"
#include <iostream>

using namespace std;

Pokemon* EvolutionManager::capturePokemon(int speciesIndex, PokemonState state) 
{
    return createPokemon(speciesIndex, state);
}

Pokemon* EvolutionManager::evolve(Pokemon* oldPokemon) 
{
    if (!oldPokemon) return nullptr;

    int nextIndex = oldPokemon->getEvolutionTargetIndex();
    if (nextIndex == 0) 
    {
        cout << "Esse Pokémon não evolui mais!" << endl;
        return oldPokemon;
    }

    PokemonState oldState = oldPokemon->getState();
    oldState.statusEvolution =+ 1;
    delete oldPokemon;

    return createPokemon(nextIndex, oldState);
}

Pokemon* EvolutionManager::createPokemon(int speciesIndex, PokemonState state) 
{
    switch (speciesIndex) 
    {
        case CHARMANDER_INDEX:
            return new Charmander(state);
        case CHARMELEON_INDEX:
            return new Charmeleon(state);
        case CHARIZARD_INDEX:
            return new Charizard(state);
        default:
            return nullptr;
    }
}
