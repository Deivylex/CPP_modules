#include "AForm.hpp"

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw Form::GradeTooLowException();
    isSign = false;
}

AForm::~AForm()
{
}

AForm::AForm(Form& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
    isSign = other.isSign;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form Grade is too high";
}
const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form Grade is too low";
}

std::string AForm::getNameForm() {return _name;}
int AForm::getGradeToExec() {return _gradeToExec;}
int AForm::getGradeToSign()  {return _gradeToSign;}
bool AForm::getIsSing() {return isSign;}

std::ostream& operator<<(std::ostream &out, const Form &form)
{
    out << "Form " << form._name << " [signed: " << (form.isSign ? "yes" : "no")
        << ", grade to sign: " << form._gradeToSign
        << ", grade to execute: " << form._gradeToExec << "]\n";
    return out;
}

void AForm::beSigned(const Bureaucrat& bcrat)
{
    if (isSign) {
        throw std::runtime_error("Form is already signed!");
    }
    if (bcrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    isSign = true;
}
AForm::execute(Bureaucrat const & executor) const
{
    if (isSign == false)
        throw std::runtime_error ("Can not execute because Form is not sign\n");
    if (executor.getGrade > _gradeToExec)
        throw std::runtime_error ("Can not execute because Bureaucrat grade is too low\n");
    executeAction();   
}