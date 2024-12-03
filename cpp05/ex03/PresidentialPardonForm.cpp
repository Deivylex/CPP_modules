#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5), target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : PresidentialPardonForm(other.target)
{
}
void PresidentialPardonForm::executeAction () const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}