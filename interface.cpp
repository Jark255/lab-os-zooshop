#include "interface.h"

#include "animal.h"
#include "zooshop.h"
#include <iostream>

void showMenu() {
    // WIP: We don't even have it yet
    // TBI: We have what we need, now it just need to be implemented
    std::cout << "\t***ZooShop***" << std::endl
              << "1) View zooshop's status" << std::endl
              << "2) Change zooshop's name" << std::endl
              << "3) Add new animal" << std::endl
              << "4) Free an animal" << std::endl
              << "5) Work with specific animal" << std::endl
              << "0) Exit" << std::endl;
}


int getChoice() {
    int result;
    std::cout << "Your choice: ";
    std::cin >> result;

    return result;
}

void addAnimal_menuOption(Zooshop& zooshop) {
    Animal* newAnimal = requestNewAnimal();
    if (newAnimal != nullptr) {
        zooshop.putAnimal(newAnimal);
    }
}

Animal* requestNewAnimal() {
    std::cout << "Which animal would you like to add?" << std::endl
              << "1) Penguin" << std::endl
              << "2) Demon" << std::endl
              << "0) Cancel adding new animal" << std::endl;

    int userChoice = -1;
    while (userChoice != 0) {
        switch (userChoice) {
        case 1:
            return requestAnimal_Penguin();
            break;

        case 2:
            return requestAnimal_Demon();
            break;

        default:
            break;
        }
        userChoice = getChoice();
    }

    return nullptr; //< Caution! It throws nullptr if angry
}

Penguin* requestAnimal_Penguin() {
    std::string name, specie;

    std::cout << "Please enter name of new penguin" << std::endl;
    std::cin >> name;

    std::cout << "Please enter specie of new penguin" << std::endl;
    std::cin >> specie;

    Penguin* result = new Penguin(name, specie);

    return result;
}

Demon* requestAnimal_Demon() {
    std::string name, specie;

    std::cout << "Please enter name of new demon" << std::endl;
    std::cin >> name;

    std::cout << "Please enter specie of new demon" << std::endl;
    std::cin >> specie;

    Demon* result = new Demon(name, specie);

    return result;
}

void freeAnimal_menuOption(Zooshop& zooshop) {
    std::cout << "What is id of to-be-released animal's cage? " << std::endl;
    int id = 0;
    std::cin >> id;

    if (!zooshop.freeAnimalById(id)) {
        std::cout << "Hmm... Strange. I guess cage " << id
                  << " is unavailable to be freed" << std::endl;
    }
}

void setZooshopName_menuOption(Zooshop& zooshop) {
    std::cout << "What is a new name? ";
    std::string name;

    char buf;
    std::cin >> buf;
    getline(std::cin, name);

    zooshop.setName(name);
}

void showMenu_workWithSpecificAnimal_submenu(const int animalId) {
    std::cout << "Currently working with: " << animalId << std::endl
              << "1) Show info" << std::endl
              << "2) Rename" << std::endl
              << "3) Change specie" << std::endl
              << "4) Change age" << std::endl
              << "5) Play" << std::endl
              << "6) Talk" << std::endl
              << "0) Return to main menu" << std::endl;
}

void renameAnimal_menuOption(Animal* animal) {
    std::string newName;
    std::cout << "What is a new name for the animal?" << std::endl;
    std::cin >> newName;

    animal->setName(newName);
}

void changeAnimalsSpecie_menuOption(Animal* animal) {
    std::string newSpecie;
    std::cout << "What is a new specie for the animal?" << std::endl;
    std::cin >> newSpecie;

    animal->setSpecie(newSpecie);
}

void changeAnimalsAge_menuOption(Animal* animal) {
    uint newAge;
    std::cout << "What is a new age for the animal?" << std::endl;
    std::cin >> newAge;

    animal->setAge(newAge);
}

void playWithAnimal_menuOption(Animal* animal) {
    animal->play();
}

void talkWithAnimal_menuOption(Animal* animal) {
    animal->say();
}
