#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Aform;


class Intern
{

    public:
    Intern();
    Intern( const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(std::string form, std::string target);
};

#endif