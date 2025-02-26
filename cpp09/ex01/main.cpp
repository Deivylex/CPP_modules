#include "RPN.hpp"

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cout << ".Syntax ./RPM [arg]\n";
    }
    try
    {           
        RPN rpn;
        rpn.handelInput(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}