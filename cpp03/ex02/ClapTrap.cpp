#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(10) 
{
    std::cout << "ClapTrap Default constructor has been called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(10) 
{
    std::cout << "ClapTrap Contructor with variable name has been called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) 
{
    std::cout << "ClapTrap Copy constructor has been called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other )
{
    if (this != &other)
    {
        _hitPoints = other ._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        _name = other._name;
        std::cout << "ClapTrap Copy assignment operator has been called." << std::endl;
    }
    return (*this);
}

ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap Destructor has been called." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        _energyPoints -= 1;
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
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
            std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl; 
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
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _hitPoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " is repaired, restoring " << amount << " hit points!" << std::endl;
        return ;
    }
    else if (_hitPoints == 0)
        std::cout << "Sorry, " << _name << " is already dead." << std::endl;
    else
        std::cout << "No energy points to repair " << _name << std::endl;
}

