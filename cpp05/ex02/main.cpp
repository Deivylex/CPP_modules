#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
   
        Bureaucrat john("John", 5);
        Bureaucrat alice("Alice", 50);

        ShrubberyCreationForm shrubbery("garden");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Zaphod");

        std::cout << john << std::endl;
        std::cout << alice << std::endl;

        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "\n--------------\n";
        alice.signForm(shrubbery);
        alice.executeForm(shrubbery);
        std::cout << "--------------\n";

        std::cout << "\n--------------\n";
        john.signForm(shrubbery);
        john.executeForm(shrubbery);
        std::cout << "\n--------------\n";

        std::cout << "\n--------------\n";
        john.signForm(robotomy);
        john.executeForm(robotomy);
        std::cout << "\n--------------\n";

        std::cout << "\n--------------\n";
        john.signForm(pardon);
        john.executeForm(pardon);
        std::cout << "\n--------------\n";

        Bureaucrat test_error("Error", 146);

        std::cout << test_error << std::endl;
        std::cout << "\ntest error--------------\n";
        ShrubberyCreationForm shrubbery2("garden");
        test_error.signForm(shrubbery2);
        test_error.executeForm(shrubbery2);
        std::cout << "--------------\n";

    return 0;
}
