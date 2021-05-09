#include "animal.h"
#include "interface.h"
#include "zooshop.h"
#include <iostream>

void workWithSpecificAnimal_submenu(Zooshop& zooshop) {
    int userChoice = -1;

    std::cout << "What is an id of animal you want to work with?" << std::endl;
    std::size_t animalId = getChoice();
    
    if (animalId >= zooshop.getAmountOfAnimals()) {
        std::cout << "We don't have such an animal" << std::endl
                  << "Returning to the main menu" << std::endl;
        return;
    }

    Animal* currentAnimal = zooshop[animalId];

    while (userChoice != 0) {
        showMenu_workWithSpecificAnimal_submenu(animalId);
        userChoice = getChoice();

        switch (userChoice) {
        case 0:
            std::cout << std::endl;
            break;

        case 1:
            std::cout << *currentAnimal << std::endl << std::endl;
            break;
        
        case 2:
            renameAnimal_menuOption(currentAnimal);
            break;

        case 3:
            changeAnimalsSpecie_menuOption(currentAnimal);
            break;

        case 4:
            changeAnimalsAge_menuOption(currentAnimal);
            break;

        case 5:
            playWithAnimal_menuOption(currentAnimal);
            break;
        
        case 6:
            talkWithAnimal_menuOption(currentAnimal);
            break;

        default:
            std::cout << "Invalid command\n" << std::endl;
            break;
        }
    }
}

int main() {
    Zooshop zooshop("The Zooshop");

    int userChoice = -1;

    while (userChoice != 0) {
        showMenu();
        userChoice = getChoice();

        switch (userChoice) {
        case 0:
            std::cout << "Have a nice day!" << std::endl;
            break;

        case 1:
            zooshop.printStatus();
            break;
        
        case 2:
            setZooshopName_menuOption(zooshop);
            break;

        case 3:
            addAnimal_menuOption(zooshop);
            break;

        case 4:
            freeAnimal_menuOption(zooshop);
            break;
        
        case 5:
            workWithSpecificAnimal_submenu(zooshop);
            break;

        default:
            std::cout << "Invalid command\n" << std::endl;
            break;
        }
    }

    return 0;
}