#pragma once

#include <string>

typedef unsigned int uint;

class Animal {
  protected:
    std::string _name;
    uint _age;
    std::string _specie;
    const std::string _typeOfAnimal;

    Animal(const std::string animalType);

  public:
    Animal();
    virtual ~Animal() = default;

    std::string getName();
    uint getAge();
    std::string getSpecie(); 

    void setName(const std::string &name);
    void setAge(const uint &age);
    void setSpecie(const std::string &specie);
    
    virtual Animal* clone() const = 0; // We can't just clone any animal before further study

    virtual void say() = 0;
    virtual void play() = 0;

    friend bool operator==(const Animal& leftAnimal, const Animal& rightAnimal);
    friend std::ostream& operator<<(std::ostream& stream, const Animal& animal);
};

class Penguin : public Animal {
  protected:
  
  public:
    Penguin(const std::string& name, const std::string& specie);

    virtual Penguin* clone() const;

    void say();
    void play();
};

class Demon : public Animal {
  protected:
  
  public:
    Demon(const std::string& name, const std::string& specie);

    virtual Demon* clone() const;

    void say();
    void play();
};
