#include "Harl.hpp"

int main(int ac, char **av) 
{
    Harl harl;

    if (ac  != 2)
    {
        std::cout << "Invalid numbers of parameters" << std::endl;
        return 0;
    }
    harl.complain(av[1]);
}