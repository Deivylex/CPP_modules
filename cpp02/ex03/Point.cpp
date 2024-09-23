#include "Point.hpp"

Point::Point() : x(0), y(0)
{
    std::cout << "Point default contructor has been called" << std::endl;
}

Point::Point(const float a, const float b) : x(a), y(b)
{
    std::cout << "Point contructor has been called" << std::endl;
}

Point::Point(const Point& other) : x(other.x), y(other.y)
{
    std::cout << "Point copy contructor has been called" << std::endl;
}

Point& Point::operator=(const Point& other)
{    
    // Since x and y are const, assignment doesn't make sense in this context.
    // Hence, we just return *this, no reassignment of members.
    std::cout << "Point assignment operator has been called" << std::endl;
    (void)other;
    return *this;
}

Point::~Point()
{
    std::cout << "Point destructor has been called" << std::endl;
}

Fixed Point::get_x() const { return x; }
Fixed Point::get_y() const { return y; }
