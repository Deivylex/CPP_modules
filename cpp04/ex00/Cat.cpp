#include "Cat.hpp"

Cat::Cat() 
{
    type = "Cat";
    std::cout << "Cat constractor has been called" << std::endl; 
}

Cat::Cat(const Cat& other) : Animal(other) {}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        type = other.type;
    return *this;
}

Cat::~Cat() { std::cout << "Cat destractor has been called" << std::endl; }

void Cat::makeSound() const
{
    std::cout << "Cat sound" << std::endl;
}