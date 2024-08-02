#include "Zombie.hpp"

Zombie::Zombie() : name(""){}

Zombie::~Zombie()
{
    std::cout << red << name << " is destroyed" << std::endl << def;
}

void    Zombie::announce() const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string new_name)
{
    this->name = new_name;
}