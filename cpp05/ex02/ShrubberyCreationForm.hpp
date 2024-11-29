#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public  AForm
{
    private:

    std::string target;

    public:

    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other) = delete;
    
    void executeAction() const override;  
};


#endif