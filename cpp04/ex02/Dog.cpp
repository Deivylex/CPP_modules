#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
    type = "Dog"; 
    std::cout << "Dog constractor has been called" << std::endl; 
}

Dog::Dog(const Dog& other) : AAnimal(other), brain(new Brain(*other.brain)) {}

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

std::string Dog::getBrainIdea(int index) const { return brain->getIdeas(index); }

void Dog::setBrainIdea(int index, const std::string& idea) 
{
    if (index >= 0 && index < 100)
        brain->setIdeas(index, idea);
    else
        std::cout << "Index out of bounds for brain ideas! " << std::endl; 
}