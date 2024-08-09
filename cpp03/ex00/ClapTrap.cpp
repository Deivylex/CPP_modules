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
        std::cout << "Copy assignment have been called." << std::endl;
    }
    return (*this);
}

ClapTrap::~ClapTrap() 
{
    std::cout << "Destructor have been called." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        _energyPoints -= 1;
        std::cout << "ClapTrap" << _name << " attacks " << target << "causing" << _attckDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " cannot attack, not enough hit points or energy!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints > 0)
    {
        if (amount > _hitPoints)
        {
            _hitPoints = 0;
            std::cout << _name << " dies" << std::endl; 
        }
        else
        {
            _hitPoints -= amount;
            std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
        }
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 )
    {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << _name << " is repaired" << std::endl;
    }
    else
        std::cout << "No enery points to repair " << _name << std::endl;
    
}
