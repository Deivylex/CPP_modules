#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {  std::cout << "Ice constructor called" << std::endl; }

Ice::Ice(const Ice& other) : AMateria(other)
{
    _type = other._type;
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
}

Ice::~Ice() {  std::cout << " Ice destructor called" << std::endl; }

AMateria* Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter& target) 
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
