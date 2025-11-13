#include "Pokemon.h"
#include <iostream>

using namespace std;

Pokemon::Pokemon(string name, int index, float height, float weight) : name(name), index(index), height(height), weight(weight) 
{
    state.shiny = false;
    state.statusEvolution = 0;
}

Pokemon::Pokemon(string name, int index, float height, float weight, PokemonState state) : name(name), index(index), height(height), weight(weight), state(state) 
{

}

PokemonState Pokemon::getState() 
{
    return state;
}

void Pokemon::printInfo() 
{
    cout << "Nome: " << name << " (" << index << ")" << endl;
    cout << "Altura: " << height << " m" << endl;
    cout << "Peso: " << weight << " kg" << endl;
    cout << "Raridade: ";
    if(state.shiny)
    {
        cout << "Shiny";
    }
    else
    {
        cout << "Normal";
    }
    cout << endl;
    cout << "Status de Evolução: " << state.statusEvolution << endl;
}
