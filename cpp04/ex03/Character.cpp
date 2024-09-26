#include "Character.hpp"

Character::Character(std::string name) : _name(name), _unequippedCount(0), _unequippedCapacity(4)
{
    _unequipped = new AMateria*[_unequippedCapacity];
    for (int i = 0; i < 4; i++)
        _inventory[i] = nullptr;
    std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character& other) 
    : _name(other._name), _unequippedCount(other._unequippedCount), _unequippedCapacity(other._unequippedCapacity) 
{
    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = nullptr; 
    }
    _unequipped = new AMateria*[_unequippedCapacity];
    for (int i = 0; i < _unequippedCount; ++i)
        _unequipped[i] = other._unequipped[i]->clone();
}


Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        _name = other._name;
        //cleaning _inventory
        for (int i = 0; i < 4; i++)
        {
            delete _inventory[i];
            _inventory[i] = nullptr;
        }
        //copy inventory
        for (int i = 0; i < 4; i++)
        {
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = nullptr; 
        }
        //cleaning trash from funtion unequip(because pdfof this exercise)
        delete[] _unequipped;
        //copy of the trash
        _unequippedCount = other._unequippedCount;
        _unequippedCapacity = other._unequippedCapacity;
        _unequipped = new AMateria*[_unequippedCapacity];
        for (int i = 0; i < _unequippedCount; ++i)
            _unequipped[i] = other._unequipped[i]->clone();
    }
    return *this;
}

Character::~Character() 
{
    for (int i = 0; i < 4; ++i)
        delete _inventory[i];
    for (int i = 0; i < _unequippedCount; ++i)
        delete _unequipped[i];
    delete[] _unequipped;
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
            return ;
        }
    }
    std::cout << _name << "'s inventory is full!" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && _inventory[idx]) 
    {
        if (_unequippedCount >= _unequippedCapacity) 
        {
            _unequippedCapacity *= 2;
            AMateria** newArray = new AMateria*[_unequippedCapacity];
            for (int i = 0; i < _unequippedCount; ++i) 
                newArray[i] = _unequipped[i];
            delete[] _unequipped;
            _unequipped = newArray;
        }
        _unequipped[_unequippedCount++] = _inventory[idx];
        _inventory[idx] = nullptr;
        std::cout << _name << " unequipped Materia from slot " << idx << std::endl;
        return ;
    }
    std::cout << idx << "   idx is out to inventory so can not unequip" << std::endl;
}