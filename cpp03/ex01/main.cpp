#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // test ClapTrap
    ClapTrap clap1("CL4P-TP");

    clap1.attack("Bandit");
    clap1.takeDamage(5);
    clap1.beRepaired(3);
    clap1.attack("Skag");
    clap1.takeDamage(15);
    clap1.beRepaired(5);
    clap1.attack("Psycho");

    //test ScavTrap
    ScavTrap scav1("carlos");
    scav1.attack("papa");
    scav1.takeDamage(10);
    scav1.beRepaired(7);
    scav1.attack("cola");
    scav1.takeDamage(100);
    scav1.beRepaired(7);
    scav1.attack("last");
    scav1.takeDamage(100);
    scav1.beRepaired(7);

    return 0;
}