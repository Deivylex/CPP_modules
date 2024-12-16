#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(){}

Intern::Intern( const Intern &other)  { (void)other; }

Intern& Intern::operator=( const Intern& other)
{
    (void)other; 
    return *this; 
}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string formName, std::string target) 
{
    std::string formNames[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    int formT = 0;

    while (formT < 3 && formNames[formT] != formName) 
        formT++;

    switch (formT) 
    {
        case 0:
            std::cout << "Intern creates " << formName << std::endl;
            return new RobotomyRequestForm(target);
        case 1:
            std::cout << "Intern creates " << formName << std::endl;
            return new PresidentialPardonForm(target);
        case 2:
            std::cout << "Intern creates " << formName << std::endl;
            return new ShrubberyCreationForm(target);
        default:
            std::cerr << "Error: Form \"" << formName << "\" does not exist!" << std::endl;
            throw std::invalid_argument("Invalid form name");
            return nullptr;
    }
}