#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat john("John", 50);
        Form taxForm("TaxForm", 40, 30);

        std::cout << taxForm << std::endl;
        john.signForm(taxForm);
        std::cout << taxForm << std::endl;

        Bureaucrat mary("Mary", 30);
        mary.signForm(taxForm);
        std::cout << taxForm << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
