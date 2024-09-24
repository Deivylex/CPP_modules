#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure :  public AMateria
{
    Cure();
    Cure(const Cure& other);
    Cure& operator=(const Cure& other);
    virtual ~Cure();

    AMateria* clone () const;
    void use(ICharacter& type) override;
};

#endif