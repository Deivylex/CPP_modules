#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

#define red "\033[1;31m"
#define def "\033[0m"

class Zombie
{
private:
    std::string name;

public:
    Zombie();
    ~Zombie();

    void announce() const;
    void setName(std::string name);
};

#endif
