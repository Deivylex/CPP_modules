#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() 
{
    Zombie *ptr_Zombie;
    Zombie first;

    first.setName("first");
    first.announce();

    randomChump("random");
    first.announce();
    ptr_Zombie = newZombie("new zombie");
    ptr_Zombie->announce();

    delete ptr_Zombie;

    return 0;
}


