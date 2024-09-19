#include "Cat.hpp"

Cat::Cat() : brain(new Brain())
{
    type = "Cat";
    std::cout << "Cat constractor has been called" << std::endl; 
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        type = other.type;
        *brain = *other.brain;
    }
    return *this;
}

Cat::~Cat() 
{ 
    std::cout << "Cat destractor has been called" << std::endl;
    delete brain;    
}

void Cat::makeSound() const
{
    std::cout << "Cat sound" << std::endl;
}