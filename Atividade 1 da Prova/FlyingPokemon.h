#ifndef FLYING_POKEMON_H
#define FLYING_POKEMON_H

#include "Pokemon.h"
#include <iostream>

class FlyingPokemon : virtual public Pokemon 
{
public:
    FlyingPokemon(string name, int index, float height, float weight);
    FlyingPokemon(string name, int index, float height, float weight, PokemonState state);

    virtual void fly();

};

#endif
