#include "RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest",72, 45), target(target){}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : RobotomyRequestForm(other.target) {}

void RobotomyRequestForm::executeAction() const
{
    std::srand(std::time(0));
    std::cout << "Bzzzzz... Drilling noises..." << std::endl;
    if (std::rand() % 2)
        std::cout << target << " has been successfully robotomized!" << std::endl;
    else
        std::cout << "Robotomy of " << target << " failed!" << std::endl;
}