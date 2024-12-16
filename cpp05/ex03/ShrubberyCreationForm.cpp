#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShBerryCreation", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : ShrubberyCreationForm(other.target) {}

void ShrubberyCreationForm::executeAction() const 
{
    
    std::ofstream file(target + "_shrubbery");
    if (!file)
        throw std::ios_base::failure("Failed to create shrubbery file");

    file << "         ccee88oo" << std::endl;
    file << "      C8O8O8Q8PoOb o8oo" << std::endl;
    file << "   dOB69QO8PdUOpugoO9bD" << std::endl;
    file << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
    file << "     6OuU  /p u gcoUodpP" << std::endl;
    file << "       \\\\//  /douUP" << std::endl;
    file << "         |||/\\\\\\" << std::endl;
    file << "         |||||||" << std::endl;
    file << "         |||||||" << std::endl;
    file << "         |||||||" << std::endl;
    file << "   .....//||||\\\\...." << std::endl;

    file.close();
    std::cout << "Shrubbery file created for " << target << std::endl;
}
