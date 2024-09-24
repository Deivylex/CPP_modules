#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice :  public AMateria
{
    public :
    
    Ice();
    Ice(const Ice& other);
    Ice& operator=(const Ice& other);
    virtual ~Ice();

    virtual AMateria* clone () const;
    void use(ICharacter& target) override;
};

#endif