#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main() 
{
    Zombie *ptr_Zombie;

    ptr_Zombie = zombieHorde(6, "deivy");

    for (size_t i = 0; i < 6; i++)
    {
        ptr_Zombie[i].announce();
    }

    delete[] ptr_Zombie;

    return 0;
}


