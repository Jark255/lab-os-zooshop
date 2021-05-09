#include "animal.h"

#include <iostream>

// A bit of preparations for easter eggs
enum KnownOS {
    __OS_WINDOWS,
    __OS_MACOS,
    __OS_UNIX
};

#if defined(WIN32) || defined(_WIN32) || \
    defined(__WIN32) && !defined(__CYGWIN__)
static const KnownOS __os_type = __OS_WINDOWS;
#elif __APPLE__
static const KnownOS __os_type = __OS_MACOS;
#else
static const KnownOS __os_type = __OS_UNIX;
#endif

Animal::Animal() {
    _name = "";
    _age = 0;
    _specie = "";
}

Animal::Animal(const std::string animalType) : _typeOfAnimal(animalType) {
    _name = "";
    _age = 0;
    _specie = "";
}

std::string Animal::getName() { return _name; }

uint Animal::getAge() { return _age; }

std::string Animal::getSpecie() { return _specie; }

void Animal::setName(const std::string& name) { _name = name; }

void Animal::setAge(const uint& age) { _age = age; }

void Animal::setSpecie(const std::string& specie) { _specie = specie; }

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

Penguin::Penguin(const std::string& name, const std::string& specie) : Animal("penguin") {
    _name = name;
    _specie = specie;
    _age = 29; // 2021-1991 - 1 year (it's not over yet)
}

Penguin* Penguin::clone() const {
    Penguin* clonedOne = new Penguin(_name, _specie);
    clonedOne->_age = _age;

    return clonedOne;
}

void Penguin::say() {
    switch (__os_type) {
        case __OS_WINDOWS:
            std::cout << "Hold on... What am I doing here!?!? LET ME OUT!!"
                    << std::endl;
            break;

        case __OS_MACOS:
            std::cout << "*excited* uUUuh! I love challenges!" << std::endl;
            break;

        default:
            std::cout << "Glad to be home!" << std::endl;
            break;
    }
}

void Penguin::play() {
    switch (__os_type) {
        case __OS_WINDOWS:
            std::cout << "*Pretends BSoD:ing every second or so*" << std::endl;
            break;
        
        case __OS_MACOS:
            std::cout << "*Tries to interact with world but sometimes fails*"
                    << std::endl;
            break;
        
        default:
            std::cout << "*Just lays down and does nothing*" << std::endl;
            break;
    }
}

Demon::Demon(const std::string& name, const std::string& specie) : Animal("demon") {
    _name = name;
    _specie = specie;
    _age = 27; // 2021-1993 -1
}

Demon* Demon::clone() const {
    Demon* clonedOne = new Demon(_name, _specie);
    clonedOne->_age = _age;

    return clonedOne;
}

void Demon::say() {
    if (lowerString(_specie) == "macos") {
        switch (__os_type) {
            case __OS_WINDOWS:
                std::cout << "Oh, hi there! How about sharing some PSD files?"
                        << std::endl;
                break;
            
            case __OS_MACOS:
                std::cout
                    << "Oh, how fortunate. I guess we _will_ be friends after all"
                    << std::endl;
                break;
            
            default:
                std::cout << "Well, at least it looks familiar" << std::endl;
                break;
        }
    } else {
        std::cout << "Welp, I'm cool, aren't I?" << std::endl;
    }
}

void Demon::play() {
    if (lowerString(_specie) == "macos") {
        switch (__os_type) {
            case __OS_WINDOWS:
                std::cout << "*Tries to get more people getting more of other "
                            "demons like him. It seems he has some results*"
                        << std::endl;
                break;
            
            case __OS_MACOS:
                std::cout << "*Enjoys the sunshine while listening to people's "
                            "screams and drinking red substance from his glass*"
                        << std::endl;
                break;
                
            default:
                std::cout << "*Tries to get more people getting more of other "
                            "demons like him very hard. But the flow of "
                            "newcommers doesn't appear bigger than before"
                        << std::endl;
                break;
        }
    } else {
        std::cout << "*Tries to look cool*" << std::endl;
    }
}
