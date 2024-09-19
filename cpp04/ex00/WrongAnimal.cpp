#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("") { std::cout << "WrongAnimal constractor has been called" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destractor has been called" << std::endl; }

std::string WrongAnimal::getType() const { return type; }

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sonds" << std::endl ;
}