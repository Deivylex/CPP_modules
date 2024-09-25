#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = nullptr;
    std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character& other) : _name (other._name)
{
    for (int i = 0; i < 4; i++)
    {
        if ( other._inventory[i] )
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = nullptr; 
    }
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        _name = other._name;
        for(int i = 0; i < 4; i++)
        {
            if (_inventory[i])
            {
                delete _inventory[i];
                _inventory[i] = nullptr;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if ( other._inventory[i] )
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = nullptr; 
        }
    }
    return (*this);
}

Character::~Character() 
{
    for(int i = 0; i < 4; i++)
    {
        if (_inventory[i])
        {
            delete _inventory[i];
            _inventory[i] = nullptr;
        }
    }
    std::cout << "Character destructor called" << std::endl; 
}

std::string const& Character::getName() const { return _name; } 

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
}

void Character::equip(AMateria* m)
{
    if (!m)
        return ;
    for(int i = 0; i < 4; i++)
    { 
        if (!_inventory[i])
        {
            _inventory[i] = m;
            std::cout << _name << " equipped " << m->getType() << " in slot " << i << std::endl;
        }
    }
    std::cout << _name << "'s inventory is full!" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && _inventory[idx])
    {
        _inventory[idx] = nullptr;
         std::cout << _name << " unequipped Materia from slot " << idx << std::endl;
    }
}