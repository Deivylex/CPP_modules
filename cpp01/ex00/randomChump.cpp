#include "Zombie.hpp"

//create a Zombien in the stack
void randomChump(std::string name)
{
    Zombie random_Z;

    random_Z.setName(name);
    random_Z.announce();
}