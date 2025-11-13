#include "Charmeleon.h"
#include <iostream>

using namespace std;

Charmeleon::Charmeleon(PokemonState state) : Pokemon("Charmeleon", CHARMELEON_INDEX, 1.1f, 19.0f, state), FirePokemon("Charmeleon", CHARMELEON_INDEX, 1.1f, 19.0f, state)
{
    cout << "Evoluiu para Charmeleon" << endl;
    cout << "Status de evolução: " << state.statusEvolution << endl;
    cout << "\n" << endl;

}

Charmeleon::~Charmeleon() 
{
    cout << "Charmeleon evoluiu!" << endl;
}

int Charmeleon::getEvolutionTargetIndex() 
{
    return CHARIZARD_INDEX;
}

void Charmeleon::burnUP() 
{
    cout << "Charmeleon usou Burn Up!" << endl;
}

void Charmeleon::printInfo() 
{
    Pokemon::printInfo();
}
