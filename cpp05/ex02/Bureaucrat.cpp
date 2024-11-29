#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) 
{
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
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

std::ostream& operator<<(std::ostream &out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << " Bureaucrat grade " << bureaucrat.getGrade();
    return out;
}

void    Bureaucrat::decrementGrade() 
{
    if (_grade + 1 > 150)
        throw GradeTooLowException(); 
    _grade++; 
}

void    Bureaucrat::incrementGrade() 
{
    if (_grade - 1 < 1)
        throw GradeTooHighException(); 
    _grade--; 
}

int    Bureaucrat::getGrade() const { return _grade; }

std::string    Bureaucrat::getName() const { return _name; }

const char* Bureaucrat::GradeTooHighException::what() const throw ()
{
    return ("it`s too hight");
}

const char* Bureaucrat::GradeTooLowException::what() const throw ()
{
    return ("it`s too low");
}

void    Bureaucrat::signForm(Form &form)
{
    try {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getNameForm() << std::endl;
    } catch (std::exception& e) {
        std::cout << getName() << " couldn't sign " << form.getNameForm()
                  << " because " << e.what() << std::endl;
    }
    
}