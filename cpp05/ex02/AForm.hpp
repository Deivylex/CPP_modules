#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
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

    AForm(const std::string name, const int gradeToSign, const int gradeToExec);
    ~AForm();
    AForm& operator=(const Form& other) = delete;
    AForm(Form& other);

    //getters
    std::string getNameForm();
    int getGradeToSign();
    int getGradeToExec();
    bool getIsSing();

    void beSigned(const Bureaucrat& bcrat);
    void execute(Bureaucrat const & executor) const;
    virtual void executeAction() const = 0;

};

#endif