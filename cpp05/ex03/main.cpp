#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() 
{
    
    Intern intern;
    Bureaucrat boss("Alice", 1);
    Bureaucrat junior("Bob", 150);

    std::cout << "\n=== Test 1: Create and sign RobotomyRequestForm ===\n" << std::endl;
    AForm* robotomy = intern.makeForm("robotomy request", "R2D2");
    std::cout << *robotomy << std::endl;

    boss.executeForm(*robotomy);

    std::cout << "\n";
    boss.signForm(*robotomy);
    std::cout << *robotomy << std::endl;
    boss.executeForm(*robotomy);
    std::cout << "\n----------\n";
    delete robotomy;
    try
    {
        std::cout << "\n=== Test 2: Create an invalid form ===" << std::endl;
        AForm* invalid = intern.makeForm("invalid form", "nowhere");
        if (invalid == nullptr)
            return (1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n=== Test 3: Create and handle ShrubberyCreationForm ===\n" << std::endl;
        AForm* shrubbery = intern.makeForm("shrubbery creation", "garden");
        std::cout << *shrubbery << std::endl;

    try {
        junior.signForm(*shrubbery);
    } catch (std::exception& e) {
        std::cerr << "Signing error: " << e.what() << std::endl;
        delete shrubbery;
    }

    boss.signForm(*shrubbery);
    boss.executeForm(*shrubbery);
    delete shrubbery;
    std::cout << "\n-------------------\n";

    std::cout << "\n=== Test 4: Create and handle PresidentialPardonForm ===\n" << std::endl;
    AForm* pardon = intern.makeForm("presidential pardon", "Zaphod Beeblebrox");
    std::cout << *pardon << std::endl;

    boss.signForm(*pardon);
    boss.executeForm(*pardon);

    delete pardon;

    std::cout << "\n=== End of tests ===" << std::endl;
    return 0;
}
