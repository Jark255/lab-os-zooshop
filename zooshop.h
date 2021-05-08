#pragma once

#include <string>
#include <vector>
#include "animal.h"

class Zooshop {
    private:
        std::string _name;
        std::vector<Animal*> _animals;
        int _amountOfAnimals;

    public:
        Zooshop();
        Zooshop(const Zooshop& originalZooshop);
        ~Zooshop();

        void printStatus();
        void setName(const std::string& name);

        void putAnimal(Animal* animal);
        Animal* getLastAnimal(); //< Also removes it from array
        bool freeAnimalById(const uint id);
        Animal* getAnimalById(const uint id);
        int getAmountOfAnimals();

        Animal* operator[](int id);
        Zooshop& operator=(const Zooshop& original);
};

