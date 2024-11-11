#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

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

    Form(const std::string name, const int _gradeToSign, const int _gradeToExec);
    ~Form();
    Form& operator=(const Form& other);
    Form(Form& other);


};

#endif