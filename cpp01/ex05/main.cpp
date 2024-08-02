#include "Harl.hpp"

int main() 
{
    Harl harl;

    std::cout << "test for debug" << std::endl;
    harl.complain("DEBUG");
    std::cout << "test for info" << std::endl;
    harl.complain("INFO");
    std::cout << "test for warning" << std::endl;
    harl.complain("WARNING");
    std::cout << "test for error" << std::endl;
    harl.complain("ERROR");
    std::cout << "Randon test" << std::endl;
    harl.complain("Randon");
}