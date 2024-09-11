#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() 
{
    std::cout << "\033[1;33m" << "test ClapTrap" << std::endl;
    ClapTrap clap1("CL4P-TP");
    clap1.attack("Bandit");
    clap1.takeDamage(5);
    clap1.beRepaired(3);
    clap1.attack("Skag");
    clap1.takeDamage(15);
    clap1.beRepaired(5);
    clap1.attack("Psycho");

    std::cout << "\033[1;91m" << "test ScavTrap" << std::endl;
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
    scav1.guardGate();

    std::cout << "\033[1;32m" << "test scavtrap applying Claptrap attack" << std::endl;
    ScavTrap scav2("noni");
    scav2.ClapTrap::attack("mommi");
    scav2.takeDamage(10);
    scav2.beRepaired(7);
    scav2.guardGate();

    std::cout << "\033[1;33m" << "test FragTrap" << std::endl;
    FragTrap fragt1("frafra");
    fragt1.attack("kuku");
    fragt1.takeDamage(10);
    fragt1.beRepaired(7);
    fragt1.attack("yumi");
    fragt1.takeDamage(100);
    fragt1.beRepaired(7);
    fragt1.attack("last");
    fragt1.takeDamage(100);
    fragt1.beRepaired(7);
    fragt1.highFivesGuys();

    return 0;
}