#include "RPN.hpp"

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cout << ".Syntax ./RPM [arg]\n";
    }
    RPN rpn;
    rpn.handelInput(av[1]);

}