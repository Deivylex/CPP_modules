#include "AAnimal.hpp"

AAnimal::AAnimal() : type("") { std::cout << "AAnimal constractor has been called" << std::endl; }

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    if (this != &other)
        type = other.type;
    return *this;
}

AAnimal::~AAnimal() { std::cout << "AAnimal destractor has been called" << std::endl; }

std::string AAnimal::getType() const { return type; }

void AAnimal::makeSound() const
{
    std::cout << type << "AAnimals sonds" << std::endl ;
}