#include "Charizard.h"
#include <iostream>

using namespace std;

Charizard::Charizard(PokemonState state) : Pokemon("Charizard", CHARIZARD_INDEX, 1.7f, 90.5f, state), FirePokemon("Charizard", CHARIZARD_INDEX, 1.7f, 90.5f, state), FlyingPokemon("Charizard", CHARIZARD_INDEX, 1.7f, 90.5f, state) 
{
    this->state.statusEvolution = 2;    
    cout << "Evoluiu para Charizard" << endl;
    cout << "Chegou ao pico da evolução!" << endl;
    cout << "Status de evolução: " << state.statusEvolution << endl;
    cout << "\n" << endl;
}

Charizard::~Charizard() 
{
    cout << "Charizard deletado" << endl;
}

int Charizard::getEvolutionTargetIndex() 
{
    return 0; 
}

void Charizard::printInfo() 
{
    Pokemon::printInfo();
}

void Charizard::burnUP() 
{
    cout << "Charizard usou Burn Up!" << endl;
}

void Charizard::fly() 
{
    cout << "Charizard voou pelos céus!" << endl;
}
