#include "animal.h"

#include <iostream>

// A bit of preparations for easter eggs
#if defined(WIN32) || defined(_WIN32) ||                                       \
    defined(__WIN32) && !defined(__CYGWIN__)
static const std::string __os_type = "Windows";
#elif __APPLE__
static const std::string __os_type = "macOS";
#else
static const std::string __os_type = "UNIX";
#endif

Animal::Animal() {
    _name = "";
    _age = 0;
    _specie = "";
    _typeOfAnimal = "";
}

std::string Animal::getName() { return _name; }

uint Animal::getAge() { return _age; }

std::string Animal::getSpecie() { return _specie; }

std::string Animal::getTypeOfAnimal() { return _typeOfAnimal; }

void Animal::setName(const std::string& name) { _name = name; }

void Animal::setAge(const uint& age) { _age = age; }

void Animal::setSpecie(const std::string& specie) { _specie = specie; }

void Animal::setTypeOfAnimal(const std::string& TypeOfAnimal) {
    _typeOfAnimal = TypeOfAnimal;
}

Animal& Animal::operator=(const Animal& original) {
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Animal& animal) {
    stream << animal._typeOfAnimal << " " << animal._specie << " named \""
           << animal._name << "\" " << animal._age << " years old";
        
    return stream;
}

bool operator==(const Animal& leftAnimal, const Animal& rightAnimal) {
    if (leftAnimal._age == rightAnimal._age &&
        leftAnimal._name == rightAnimal._name &&
        leftAnimal._specie == rightAnimal._specie &&
        leftAnimal._typeOfAnimal == rightAnimal._typeOfAnimal) {
        return true;
    }

    return false;
}

static const std::string lowerString(const std::string& string) {
    std::string result;
    for (char character : string) {
        result.push_back(std::tolower(character));
    }

    return result;
}

Penguin::Penguin(const std::string& name, const std::string& specie) {
    _name = name;
    _specie = specie;
    _age = 29; // 2021-1991 - 1 year (it's not over yet)
    _typeOfAnimal = "penguin";
}

void Penguin::say() {
    if (__os_type == "Windows") {
        std::cout << "Hold on... What am I doing here!?!? LET ME OUT!!"
                  << std::endl;
    } else if (__os_type == "macOS") {
        std::cout << "*excited* uUUuh! I love challenges!" << std::endl;
    } else {
        std::cout << "Glad to be home!" << std::endl;
    }
}

void Penguin::play() {
    if (__os_type == "Windows") {
        std::cout << "*Pretends BSoD:ing every second or so*" << std::endl;
    } else if (__os_type == "macOS") {
        std::cout << "*Tries to interact with world but sometimes fails*"
                  << std::endl;
    } else {
        std::cout << "*Just lays down and does nothing*" << std::endl;
    }
}

Demon::Demon(const std::string& name, const std::string& specie) {
    _name = name;
    _specie = specie;
    _age = 27; // 2021-1993 -1
    _typeOfAnimal = "demon";
}

void Demon::say() {
    if (lowerString(_specie) == "macos") {
        if (__os_type == "Windows") {
            std::cout << "Oh, hi there! How about sharing some PSD files?"
                      << std::endl;
        } else if (__os_type == "macOS") {
            std::cout
                << "Oh, how fortunate. I guess we _will_ be friends after all"
                << std::endl;
        } else {
            std::cout << "Well, at least it looks familiar" << std::endl;
        }
    } else {
        std::cout << "Welp, I'm cool, aren't I?" << std::endl;
    }
}

void Demon::play() {
    if (lowerString(_specie) == "macos") {
        if (__os_type == "Windows") {
            std::cout << "*Tries to get more people getting more of other "
                         "demons like him. It seems he has some results*"
                      << std::endl;
        } else if (__os_type == "macOS") {
            std::cout << "*Enjoys the sunshine while listening to people's "
                         "screams and drinking red substance from his glass*"
                      << std::endl;
        } else {
            std::cout << "*Tries to get more people getting more of other "
                         "demons like him very hard. But the flow of "
                         "newcommers doesn't appear bigger than before"
                      << std::endl;
        }
    } else {
        std::cout << "*Tries to look cool*" << std::endl;
    }
}
