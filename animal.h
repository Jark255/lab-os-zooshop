#pragma once

#include <string>

typedef unsigned int uint;

class Animal {
  protected:
    std::string _name;
    uint _age;
    std::string _specie;
    std::string _typeOfAnimal;

  public:
    Animal();
    virtual ~Animal() = default;

    std::string getName();
    uint getAge();
    std::string getSpecie(); 
    std::string getTypeOfAnimal();

    void setName(const std::string &name);
    void setAge(const uint &age);
    void setSpecie(const std::string &specie);
    void setTypeOfAnimal(const std::string &TypeOfAnimal);
    
    virtual void say() = 0;
    virtual void play() = 0;

    Animal& operator=(const Animal& original);
    friend bool operator==(const Animal& leftAnimal, const Animal& rightAnimal);
    friend std::ostream& operator<<(std::ostream& stream, const Animal& animal);
};

class Penguin : public Animal {
  public:
    Penguin(const std::string& name, const std::string& specie);

    void say();
    void play();
};

class Demon : public Animal {
  public:
    Demon(const std::string& name, const std::string& specie);

    void say();
    void play();
};
