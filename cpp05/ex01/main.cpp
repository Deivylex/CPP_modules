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

        Form taxForm2("TaxForm", 40, 30);
        Bureaucrat jose("jose", 40);
        jose.signForm(taxForm2);
        std::cout << taxForm2 << std::endl;

        Form taxForm3("TaxForm", 40, 30);
        Bureaucrat okok("okok", 20);
        okok.signForm(taxForm3);
        std::cout << taxForm3 << std::endl;

        Bureaucrat lolo("lolo", 0);
        lolo.signForm(taxForm);
        std::cout << taxForm << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
