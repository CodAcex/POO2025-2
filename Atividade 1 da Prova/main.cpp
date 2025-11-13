#include <iostream>
#include <cstdlib>
#include <ctime>
#include "EvolutionManager.h"

using namespace std;

PokemonState generateRandomState()
{
    PokemonState state;
    int chance = rand() % 2; 
    if (chance == 1)
        state.shiny = true;
    else
        state.shiny = false;

    state.statusEvolution = 0;
    return state;
}

void resizeBag(Pokemon**& bag, int& capacity, int newCapacity)
{
    Pokemon** newBag = new Pokemon*[newCapacity];
    
    int i;
    for (i = 0; i < newCapacity; i++)
    {
        if (i < capacity)
            newBag[i] = bag[i];
        else
            newBag[i] = NULL;
    }

    delete[] bag;
    bag = newBag;
    capacity = newCapacity;
}

int main()
{
    srand(time(NULL));

    EvolutionManager manager;

    int capacity = 2;   
    int count = 0;       
    
    Pokemon** bag = new Pokemon*[capacity];
    int i;
    for (i = 0; i < capacity; i++)
        bag[i] = NULL;

    PokemonState state1 = generateRandomState();
    if (count == capacity)
        resizeBag(bag, capacity, capacity * 2);
    bag[count] = manager.capturePokemon(4, state1);
    count++;

    PokemonState state2 = generateRandomState();
    if (count == capacity)
        resizeBag(bag, capacity, capacity * 2);
    bag[count] = manager.capturePokemon(4, state2);
    count++;

    PokemonState state3 = generateRandomState();
    if (count == capacity)
        resizeBag(bag, capacity, capacity * 2);
    bag[count] = manager.capturePokemon(4, state3);
    count++;

    cout << "Evoluindo" << endl;
    for (i = 0; i < count; i++)
    {
        Pokemon* evolved = bag[i];
        while (evolved->getEvolutionTargetIndex() != 0)
            {
                evolved = manager.evolve(evolved);
            }
        bag[i] = evolved;
    }

    cout << "MOCHILA";
    for (i = 0; i < count; i++)
    {
        cout << "\nPokemon [" << i << "]:" << endl;
        bag[i]->printInfo();
    }

    delete[] bag;

    return 0;
}
