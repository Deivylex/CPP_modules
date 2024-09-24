#include "Character.hpp"

Character::Character(std::string name) : name(_name)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = nullptr;
    std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character& other)
{

}

Character& Character::operator=(const Character& other)
{

}

Character::~Character() { std::cout << "Character destructor called" << std::endl; }

std::string const& Character::getName()
{

}