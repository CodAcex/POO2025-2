#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include "PokemonState.h"

using namespace std;

class Pokemon {
public:
    Pokemon(string name, int index, float height, float weight);
    Pokemon(string name, int index, float height, float weight, PokemonState state);
    virtual ~Pokemon() {}

    PokemonState getState();
    virtual int getEvolutionTargetIndex() = 0;
    virtual void printInfo();

protected:
    string name;
    int index;
    float height;
    float weight;
    PokemonState state;
    Pokemon() : name(""), index(0), height(0.0f), weight(0.0f) {}

};

#endif
