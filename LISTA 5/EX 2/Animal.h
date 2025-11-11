#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using namespace std;

class Animal
{
    public:
        Animal(string nome, string Som_Bicho);
        virtual void fazerSom() = 0; // Método Virtual que torna animal em uma classe abstrata
        ~Animal();
        
    protected:
        string nome;
        string Som_Bicho;

};
#endif