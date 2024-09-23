#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) //Dog and Cat will create their Brain using new Brain()
{
    type = "Cat";
    std::cout << "Cat constractor has been called" << std::endl; 
}

Cat::Cat(const Cat& other) : AAnimal(other), brain(new Brain(*other.brain)) {} //Dog and Cat will create their Brain using new Brain()

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

std::string Cat::getBrainIdea(int index) const { return brain->getIdeas(index); }

void Cat::setBrainIdea(int index, const std::string& idea) 
{
    if (index >= 0 && index < 100)
        brain->setIdeas(index, idea);
    else
        std::cout << "Index out of bounds for brain ideas! " << std::endl; 
}