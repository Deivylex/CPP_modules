#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _name = "";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor has been called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap constructor has been called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _name = other._name;
    _attackDamage = other._attackDamage;

    std::cout << "ScavTrap Copy constructor has been called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _name = other._name;
        _attackDamage = other._attackDamage;
        std::cout << "ScavTrap Copy assignment operator has been called." << std::endl;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor has been called." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        _energyPoints -= 1;
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ScavTrap " << _name << " cannot attack, not enough hit points or energy!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}
