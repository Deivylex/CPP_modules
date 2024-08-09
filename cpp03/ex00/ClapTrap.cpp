#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attckDamage(10) 
{
    std::cout << "Defoult contructor have been called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attckDamage(10) 
{
    std::cout << "Contructor with variable name have been called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy contructor have been called." << std::endl;
    *this = other; 
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other )
{
    if (this != &other)
    {
        _hitPoints = other ._hitPoints;
        _energyPoints = other._energyPoints;
        _attckDamage = other._attckDamage;
        _name = other._name;
        std::cout << "Copy assignment have been called." << std::endl;(necesari?)
    }
    return (*this);
}

ClapTrap::~ClapTrap() 
{
    std::cout << "Destructor have been called." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (target._hitPoints > 0 && target._energyPoints)
    {
        if (target._hitPoints )
        target._hitPoints -= target._attckDamage
        target._energyPoints -= 1;
    }
}
void ClapTrap::takeDamage(unsigned int amount)
{

}
void ClapTrap::beRepaired(unsigned int amount)
{

}
