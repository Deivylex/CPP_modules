#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
    type = "Dog"; 
    std::cout << "Dog constractor has been called" << std::endl; 
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        type = other.type;
        *brain = *other.brain;
    }
    return *this;
}

Dog::~Dog() 
{ 
    std::cout << "Dog destractor has been called" << std::endl;
    delete brain; 
}

void Dog::makeSound() const 
{
    std::cout << "Dog sound" << std::endl;
}