#include "Fixed.hpp"
#define float_fractional 256.0f

Fixed::Fixed() : fixed_p(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& other) 
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed( const int num )
{
    std::cout << "Int constructor called" << std::endl;
    fixed_p = num << fractional_b;
}
Fixed::Fixed( const float num )
{
    std::cout << "Float constructor calle" << std::endl;
    fixed_p = roundf(num * (1 << fractional_b));
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;  
    if (this != &other)
    {
        fixed_p = other.fixed_p;
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

int Fixed::toInt( void ) const
{
    return (fixed_p >> fractional_b);
}

float Fixed::toFloat( void ) const
{
    return static_cast<float>(fixed_p) / float_fractional;
}

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
    out << value.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed& other) const { return fixed_p > other.fixed_p; }

bool Fixed::operator<(const Fixed& other) const { return fixed_p < other.fixed_p; }

bool Fixed::operator>=(const Fixed& other) const { return fixed_p >= other.fixed_p; }

bool Fixed::operator<=(const Fixed& other) const { return fixed_p <= other.fixed_p; }

bool Fixed::operator==(const Fixed& other) const { return fixed_p == other.fixed_p; }

bool Fixed::operator!=(const Fixed& other) const { return fixed_p != other.fixed_p; }

Fixed Fixed::operator+(const Fixed& other) const { return Fixed(toFloat() + other.toFloat()); }

Fixed Fixed::operator+(const Fixed& other) const { return Fixed(toFloat() - other.toFloat()); }

Fixed Fixed::operator+(const Fixed& other) const { return Fixed(toFloat() * other.toFloat()); }

Fixed Fixed::operator+(const Fixed& other) const { return Fixed(toFloat() / other.toFloat()); }

Fixed& Fixed::operator++() 
{
    ++fixed_p;
    return *this;
}
Fixed Fixed::operator++(int) 
{
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() 
{
    --fixed_p;
    return *this;
}
Fixed Fixed::operator--(int) 
{
    Fixed temp = *this;
    --(*this);
    return temp;
}