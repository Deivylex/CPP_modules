#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    virtual ~AForm();
    AForm& operator=(const AForm& other) = delete;

    std::string getNameForm() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    bool isSigned() const;

    void beSigned(const Bureaucrat& bureaucrat);
    void execute(const Bureaucrat& executor) const; //tengo que arreglas esto 

    virtual void executeAction() const = 0;

    friend std::ostream& operator<<(std::ostream& out, const AForm& form);
};

#endif
