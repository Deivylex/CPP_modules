#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    public:

        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat &other);
    Bureaucrat(const Bureaucrat &other);

    void incrementGrade();
    void decrementGrade();  

    std::string getName() const;
    int getGrade() const;

    friend std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

    private:
    const std::string _name;
    int _grade;    

};

#endif