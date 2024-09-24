#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice :  public AMateria
{
    Ice();
    Ice(const Ice& other);
    Ice& operator=(const Ice& other);
    ~Ice();

    Ice& clone ();
    void use(ICharacter& type) override;
};

#endif