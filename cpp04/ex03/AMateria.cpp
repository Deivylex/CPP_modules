#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {  std::cout << "AMateria constructor called" << std::endl; }

AMateria::AMateria(const AMateria& other)
{
    _type = other._type;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
}

AMateria::~AMateria() {  std::cout << " AMateria destructor called" << std::endl; }

std::string const& AMateria::getType() const { return _type; }
