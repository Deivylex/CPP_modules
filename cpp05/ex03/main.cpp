#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() 
{
    try {
        Intern intern;
        Bureaucrat boss("Alice", 1);
        Bureaucrat junior("Bob", 150);

        std::cout << "=== Test 1: Create and sign RobotomyRequestForm ===" << std::endl;
        AForm* robotomy = intern.makeForm("robotomy request", "R2D2");
        std::cout << *robotomy << std::endl;

        try {
            boss.executeForm(*robotomy);
        } catch (std::exception& e) {
            std::cerr << "Execution error: " << e.what() << std::endl;
        }

        robotomy->beSigned(boss);
        boss.executeForm(*robotomy);

        delete robotomy;

        std::cout << "=== Test 2: Create an invalid form ===" << std::endl;
        try {
            AForm* invalid = intern.makeForm("invalid form", "nowhere");
            delete invalid;
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        std::cout << "=== Test 3: Create and handle ShrubberyCreationForm ===" << std::endl;
        AForm* shrubbery = intern.makeForm("shrubbery creation", "garden");
        std::cout << *shrubbery << std::endl;

        try {
            shrubbery->beSigned(junior);
        } catch (std::exception& e) {
            std::cerr << "Signing error: " << e.what() << std::endl;
        }

        shrubbery->beSigned(boss);
        boss.executeForm(*shrubbery);

        delete shrubbery;

        std::cout << "=== Test 4: Create and handle PresidentialPardonForm ===" << std::endl;
        AForm* pardon = intern.makeForm("presidential pardon", "Zaphod Beeblebrox");
        std::cout << *pardon << std::endl;

        pardon->beSigned(boss);
        boss.executeForm(*pardon);

        delete pardon;

    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "=== End of tests ===" << std::endl;
    return 0;
}
