#include "Fixed.hpp"

Fixed::Fixed() : fixed_p(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& other) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;  
    if (this != &other)
    {
        fixed_p = other.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_p);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "getRawBits member function called" << std::endl;
    fixed_p = raw;
}