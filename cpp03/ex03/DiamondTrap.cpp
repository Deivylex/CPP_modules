#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
    this->_name = "";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
    this->_name = name;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : FragTrap(other), ScavTrap(other), ClapTrap(other)
{
    ClapTrap::_name = other._name;
    FragTrap::_hitPoints = other._hitPoints;
    ScavTrap::_energyPoints = other._energyPoints;
    FragTrap::_attackDamage = other._attackDamage;
    std::cout << "DiamondTrap Copy constructor has been called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if(this != &other)
    {
        ClapTrap::_name = other._name;
        FragTrap::_hitPoints = other._hitPoints;
        ScavTrap::_energyPoints = other._energyPoints;
        FragTrap::_attackDamage = other._attackDamage;
        std::cout << "DiamondTrap operator assignment has been called" << std::endl;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor has been called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}