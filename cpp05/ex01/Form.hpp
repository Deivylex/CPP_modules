#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
    private :
    
    const std::string _name;
    bool isSign;
    const int _gradeToSign;
    const int _gradeToExec;

    public :

    class GradeTooHighException : public std::exception 
    {
        public :
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception 
    {
        public :
            virtual const char* what() const throw();
    };

    friend std::ostream& operator<<(std::ostream &out, const Form &form);

    Form(const std::string name, const int gradeToSign, const int gradeToExec);
    ~Form();
    Form& operator=(const Form& other) = delete;
    Form(Form& other);

    //getters
    std::string getNameForm();
    int getGradeToSign();
    int getGradeToExec();
    bool getIsSing();

    void beSigned(const Bureaucrat& bcrat);

};

#endif