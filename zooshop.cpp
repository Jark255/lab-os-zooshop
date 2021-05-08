#include "zooshop.h"
#include <iostream>

Zooshop::Zooshop() {
    _name = "Zooshop";
    _amountOfAnimals = 0;
}

Zooshop::Zooshop(const Zooshop& originalZooshop) {
    _name = originalZooshop._name;
    _amountOfAnimals = originalZooshop._amountOfAnimals;
    for (Animal* animal : originalZooshop._animals) {
        Animal* clonedAnimal = animal;
        _animals.push_back(clonedAnimal);
    }
}

Zooshop::~Zooshop() {
    for (Animal* animal : _animals) {
        delete animal;
    }
    _animals.clear();
}

void Zooshop::printStatus() {
    std::cout<< "\"" << _name << "\":" <<std::endl;

    int counter = 0;
    for (Animal* animal : _animals) {
        std::cout<< "\t" << counter++ << "." << *animal << "." << " " << std::endl; 
    }

    std::cout << std::endl;
}

void Zooshop::setName(const std::string& name) {
    _name = name;
}

void Zooshop::putAnimal(Animal* animal) {
    _animals.push_back(animal);
    ++_amountOfAnimals;
}

Animal* Zooshop::getLastAnimal() {
    Animal* animalInHands = _animals[_amountOfAnimals-1];
    _animals.pop_back();
    --_amountOfAnimals;

    return animalInHands;
}

bool Zooshop::freeAnimalById(const uint id) {
    if (id >= (uint)_amountOfAnimals) {
        return false;
    }

    delete _animals[id];
    _animals.erase(_animals.begin() + id);
    --_amountOfAnimals;

    return true;
}

Animal* Zooshop::getAnimalById(const uint id) {
    return _animals[id];
}

int Zooshop::getAmountOfAnimals() { return _amountOfAnimals; }

Animal* Zooshop::operator[](int id) {
    Animal* ref = _animals[id];

    return ref;
}

Zooshop& Zooshop::operator=(const Zooshop& original) {
    if (&original == this) {
        return *this;
    }

    _animals.clear();

    for (Animal* animal : original._animals) {
        Animal* clone = animal;
        _animals.push_back(clone);
    }

    return *this;
}
