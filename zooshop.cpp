#include "zooshop.h"
#include <algorithm>
#include <iostream>

Zooshop::Zooshop(const std::string name) { _name = name; }

Zooshop::Zooshop(const Zooshop& originalZooshop) {
    _name = originalZooshop._name;
    for (Animal* animal : originalZooshop._animals) {
        Animal* clonedAnimal = animal->clone();
        _animals.push_back(clonedAnimal);
    }
}

Zooshop::~Zooshop() {
    for (Animal* animal : _animals) {
        delete animal;
    }
}

void Zooshop::printStatus() {
    std::cout << "\"" << _name << "\":" << std::endl;

    std::cout << "There are " << getAmountOfCages() << " cages, "
              << getAmountOfFreeCages()
              << " are free and"
                 " in the others are:"
              << std::endl;

    const std::size_t n = getAmountOfAnimals();
    for (std::size_t i = 0; i < n; ++i) {
        Animal* animal = _animals[i];
        std::cout << "\t" << i << "." << *animal << "."
                  << " " << std::endl;
    }

    std::cout << std::endl;
}

void Zooshop::setName(const std::string& name) { _name = name; }

void Zooshop::putAnimal(Animal* animal) { _animals.push_back(animal); }

Animal* Zooshop::getLastAnimal() {
    if (_animals.empty()) {
        return nullptr;
    }

    Animal* animalInHands = _animals.back();
    _animals.pop_back();

    return animalInHands;
}

bool Zooshop::freeAnimalById(const std::size_t id) {
    if (id >= _animals.size()) {
        return false;
    }

    delete _animals[id];
    _animals.erase(_animals.begin() + id);

    return true;
}

std::size_t Zooshop::getAmountOfAnimals() { return _animals.size(); }

std::size_t Zooshop::getAmountOfCages() { return _animals.capacity(); }

std::size_t Zooshop::getAmountOfFreeCages() {
    return (_animals.capacity() - _animals.size());
}

Animal* Zooshop::operator[](std::size_t id) {
    Animal* ref = _animals[id];

    return ref;
}

Zooshop& Zooshop::operator=(const Zooshop& original) {
    if (&original == this) {
        return *this;
    }

    for (Animal* animal : _animals) {
        delete animal;
    }

    _animals.clear();

    for (Animal* animal : original._animals) {
        Animal* clone = animal->clone();
        _animals.push_back(clone);
    }

    return *this;
}

bool operator==(const Zooshop& left, const Zooshop& right) {
    if (left._animals.size() != right._animals.size()) {
        return false;
    }

    std::vector<Animal*> temporaryArray = right._animals;

    for (Animal* animal : left._animals) {
        std::vector<Animal*>::iterator position =
            std::find(temporaryArray.begin(), temporaryArray.end(), animal);
        
        if (position != temporaryArray.end()) {
            temporaryArray.erase(position);
        } else {
            return false;
        }
    }

    if (temporaryArray.size() != 0) {
        return false;
    }

    return true;
}
