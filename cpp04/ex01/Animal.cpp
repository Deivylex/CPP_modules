#include "Animal.hpp"

Animal::Animal() : type("") { std::cout << "Animal constractor has been called" << std::endl; }

Animal::Animal(const Animal& other) : type(other.type) {}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        type = other.type;
    return *this;
}

Animal::~Animal() { std::cout << "Animal destractor has been called" << std::endl; }

std::string Animal::getType() const { return type; }

void Animal::makeSound() const
{
    std::cout << type << "Animals sonds" << std::endl ;
}