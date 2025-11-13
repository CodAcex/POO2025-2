#ifndef FIRE_POKEMON_H
#define FIRE_POKEMON_H

#include "Pokemon.h"
#include <iostream>
using namespace std;


class FirePokemon : virtual public Pokemon {
public:
    FirePokemon(string name, int index, float height, float weight);
    FirePokemon(string name, int index, float height, float weight, PokemonState state);

    virtual void burnUP();

};

#endif
