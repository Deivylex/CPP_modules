#ifndef CHARACTER_HPP
#define CHARACTER_HPP


#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
    private :

    std::string _name;
    AMateria* _inventory[4];
    void clearInventory();
    void copyInventory ( const Character& other );

    public :

    Character(std::string name);
    Character(const Character& other);
    Character& operator=(Character& other);
    ~Character();

    std::string const & getName() const override;
    void equip(AMateria* m) override;
    void unequip(int idx) override;
    void use(int idx, ICharacter& target) override;

};

#endif