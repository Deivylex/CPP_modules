#include "Dog.hpp"

Dog::Dog() 
{
    type = "Dog"; 
    std::cout << "Dog constractor has been called" << std::endl; 
}

Dog::Dog(const Dog& other) : Animal(other) {}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        type = other.type;
    return *this;
}

Dog::~Dog() { std::cout << "Dog destractor has been called" << std::endl; }

void Dog::makeSound() const 
{
    std::cout << "Dog sound" << std::endl;
}