#include "ClapTrap.hpp"

int main() {
    // Crear un objeto ClapTrap con un nombre
    ClapTrap clap1("CL4P-TP");

    // Atacar a un objetivo
    clap1.attack("Bandit");

    // Recibir daño
    clap1.takeDamage(5);

    // Reparar el ClapTrap
    clap1.beRepaired(3);

    // Intentar atacar de nuevo
    clap1.attack("Skag");

    // Recibir daño suficiente para destruirlo
    clap1.takeDamage(15);

    // Intentar reparar después de ser destruido
    clap1.beRepaired(5);

    // Intentar atacar después de ser destruido
    clap1.attack("Psycho");

    return 0;
}