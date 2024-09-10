#include "ClapTrap.hpp"

int main() 
{
    ClapTrap clap1("CL4P-TP");

    clap1.attack("Bandit");

    clap1.takeDamage(5);

    clap1.beRepaired(3);

    clap1.attack("Skag");

    clap1.takeDamage(15);

    clap1.beRepaired(5);

    clap1.attack("Psycho");

    return 0;
}