#include "Fixed.hpp"

Fixed::Fixed() : fixed_p(0) {}

Fixed::Fixed( const &Fixed other) : fixed_p(other.fixed_p) {}

Fixed& Fixed::operator=(const Fixed& other)
{

}

~Fixed() {}

int Fixed::getRawBits( void ) const
{
    return (this->fixed_p);
}

void setRawBits( int const raw )
{
    raw = fixed_p;
}


