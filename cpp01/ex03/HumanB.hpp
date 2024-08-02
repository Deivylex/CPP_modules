#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB 
{
private:
    std::string name;
    Weapon* weapon;  

public:
    HumanB(const std::string& name);
    void setWeapon(Weapon& weaponNew);
    void attack() const;
};

#endif
