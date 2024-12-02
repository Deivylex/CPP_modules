#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat john("John", 5);
        Bureaucrat alice("Alice", 145);

        ShrubberyCreationForm shrubbery("garden");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Zaphod");

        std::cout << john << std::endl;
        std::cout << alice << std::endl;

        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        // Alice intenta firmar el formulario de Shrubbery
        alice.signForm(shrubbery);
        // Alice intenta ejecutar el formulario de Shrubbery (debería fallar)
        try {
            alice.executeForm(shrubbery);
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

        // John firma y ejecuta los formularios
        john.signForm(shrubbery);
        john.executeForm(shrubbery);

        john.signForm(robotomy);
        john.executeForm(robotomy);

        john.signForm(pardon);
        john.executeForm(pardon);
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
