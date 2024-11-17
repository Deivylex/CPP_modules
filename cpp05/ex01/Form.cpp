#include "Form.hpp"

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw Form::GradeTooLowException();
    isSign = false;
}

Form::~Form()
{
}

Form::Form(Form& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
    isSign = other.isSign;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form Grade is too high";
}
const char* Form::GradeTooLowException::what() const throw()
{
    return "Form Grade is too low";
}

std::string Form::getNameForm() {return _name;}
int Form::getGradeToExec() {return _gradeToExec;}
int Form::getGradeToSign()  {return _gradeToSign;}
bool Form::getIsSing() {return isSign;}

std::ostream& operator<<(std::ostream &out, const Form &form)
{
    out << "Form " << form._name << " [signed: " << (form.isSign ? "yes" : "no")
        << ", grade to sign: " << form._gradeToSign
        << ", grade to execute: " << form._gradeToExec << "]\n";
    return out;
}

void Form::beSigned(const Bureaucrat& bcrat)
{
    if (isSign) {
        throw std::runtime_error("Form is already signed!");
    }
    if (bcrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    isSign = true;
}