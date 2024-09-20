#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain constractor has been called" << std::endl; }

Brain::Brain(const Brain& other) 
{
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}
Brain::~Brain() { std::cout << "Brain destractor has been called" << std::endl; }

 void Brain::setIdeas(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
    else 
        std::cout << "Index out of bounds for brain ideas!" << std::endl;
}

std::string Brain::getIdeas(int index) 
{
    if (index >= 0 && index < 100) 
        return ideas[index];
    return ""; 
}

void Brain::printIdeas() const
{
    for (int i = 0; i < 100; i++)
        std::cout << "ideas[" << i << "]: " << ideas[i] << std::endl;
}