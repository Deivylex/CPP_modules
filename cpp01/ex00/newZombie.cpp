#include "Zombie.hpp"

//create a Zombien in the head
Zombie* newZombie( std::string name )
{
    Zombie *new_zombie;

    new_zombie = new Zombie();
    new_zombie->setName(name);
    return new_zombie;
}