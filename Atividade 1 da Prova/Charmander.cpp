#include "Charmander.h"
#include <iostream>

using namespace std;

Charmander::Charmander(PokemonState state) : Pokemon("Charmeleon", CHARMELEON_INDEX, 1.1f, 19.0f, state), FirePokemon("Charmander", CHARMANDER_INDEX, 0.6f, 8.5f, state) 
{
    cout << "Charmander capturado com sucesso" << endl;
    cout << "Status de evolução: " << state.statusEvolution << endl;
    cout << "\n" << endl;

}

Charmander::~Charmander() 
{
    cout << "Charmander evoluiu!" << endl;
}

int Charmander::getEvolutionTargetIndex() 
{
    return CHARMELEON_INDEX;
}

void Charmander::printInfo() 
{
    Pokemon::printInfo();
}

void Charmander::burnUP() 
{
    cout << "Charmander usou Burn Up!" << endl;
}
