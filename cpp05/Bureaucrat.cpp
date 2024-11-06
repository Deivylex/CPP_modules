#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) 
{
    if (grade > 150)
        throw GradeTooHighException();
    if (grade < 1)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) //only grade because name is constant
{
    if (this != &other)
    {
       _grade = other._grade;
    }    
    return *this;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << " Bureaucrat grade " << bureaucrat.getGrade();
    return out;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    std::cout << "Grade is too high" << std::endl;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    std::cout << "Grade is too low" << std::endl;
}

void    Bureaucrat::incrementGrade() 
{
    if (_grade + 1 > 150)
        throw GradeTooHighException(); 
    _grade++; 
}

void    Bureaucrat::decrementGrade() 
{
    if (_grade - 1 < 1)
        throw GradeTooLowException(); 
    _grade--; 
}

int    Bureaucrat::getGrade() const { return _grade; }

std::string    Bureaucrat::getName() const { return _name; }