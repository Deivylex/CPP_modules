#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << "Min between a and b: " << Fixed::min( a, b ) << std::endl;
    Fixed c(42.42f);
    Fixed d(10);

    std::cout << "c: " << c << ", d: " << d << std::endl;
    std::cout << "c + d: " << (c + d) << std::endl;
    std::cout << "c - d: " << (c - d) << std::endl;
    std::cout << "c * d: " << (c * d) << std::endl;
    std::cout << "c / d: " << (c / d) << std::endl; 

    std::cout << std::boolalpha;  // show "true"/"false" en vez de 1/0
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    std::cout << "Decrementing a: " << --a << std::endl;
    std::cout << "Post-decrement a: " << a-- << std::endl;
    std::cout << "Value of a after post-decrement: " << a << std::endl;

    return 0;
}
