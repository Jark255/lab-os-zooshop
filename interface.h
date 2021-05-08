#pragma once

#include "zooshop.h"
#include "animal.h"

void showMenu();
int getChoice();

void addAnimal_menuOption(Zooshop& zooshop);
Animal* requestNewAnimal();
Penguin* requestAnimal_Penguin();
Demon* requestAnimal_Demon();

void freeAnimal_menuOption(Zooshop& zooshop);

void setZooshopName_menuOption(Zooshop& zooshop);

void showMenu_workWithSpecificAnimal_submenu(const int animalId);
void renameAnimal_menuOption(Animal* animal);
void changeAnimalsSpecie_menuOption(Animal* animal);
void changeAnimalsAge_menuOption(Animal* animal);
void playWithAnimal_menuOption(Animal* animal);
void talkWithAnimal_menuOption(Animal* animal);