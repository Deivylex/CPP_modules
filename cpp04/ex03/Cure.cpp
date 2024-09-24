#include "Cure.hpp"

Cure::Cure() : AMateria("Cure") {  std::cout << "Cure constructor called" << std::endl; }

Cure::Cure(const Cure& other) : AMateria(other)
{
    _type = other._type;
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
}

Cure::~Cure() {  std::cout << " Cure destructor called" << std::endl; }

AMateria* Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter& target) 
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}