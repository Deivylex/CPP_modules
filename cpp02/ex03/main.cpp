#include "Point.hpp"

int main( void ) 
{
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);
    Point p1(2, 2);
    Point p2(6, 6);
    Point p3(0, 0);

    if (bsp(a, b, c, p1) == true)
        std::cout << "Point P1 is inside of the triangle" << std::endl;
    else
        std::cout << "Point P1 is out of the triangle" << std::endl;
    if (bsp(a, b, c, p2) == true)
        std::cout << "Point P2 is inside of the triangle" << std::endl;
    else
        std::cout << "Point P2 is out of the triangle" << std::endl;
    if (bsp(a, b, c, p3) == true)
        std::cout << "Point P3 is inside of the triangle" << std::endl;
    else
        std::cout << "Point P3 is out of the triangle" << std::endl; 

    return 0;
}
