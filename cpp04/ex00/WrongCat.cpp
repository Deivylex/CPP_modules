#include "WrongCat.hpp"

WrongCat::WrongCat() 
{
    type = "WrongCat"; 
    std::cout << "WrongCat constractor has been called" << std::endl; 
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        type = other.type;
    return *this;
}

WrongCat::~WrongCat() { std::cout << "WrongCat destractor has been called" << std::endl; }

void WrongCat::makeSound() const
{
    std::cout << "WrongCat sound" << std::endl;
}