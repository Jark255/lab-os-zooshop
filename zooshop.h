#pragma once

#include <string>
#include <vector>
#include "animal.h"

class Zooshop {
    private:
        std::string _name;
        std::vector<Animal*> _animals;

    public:
        Zooshop(const std::string name);
        Zooshop(const Zooshop& originalZooshop);
        ~Zooshop();

        void printStatus();
        void setName(const std::string& name);

        void putAnimal(Animal* animal);
        Animal* getLastAnimal(); //< Also removes it from array
        bool freeAnimalById(const std::size_t id);
        std::size_t getAmountOfAnimals();
        std::size_t getAmountOfCages();
        std::size_t getAmountOfFreeCages();

        Animal* operator[](std::size_t id);
        Zooshop& operator=(const Zooshop& original);
        friend bool operator==(const Zooshop& left, const Zooshop& right);
};

