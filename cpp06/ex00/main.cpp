#include "ScalarConverter.hpp"

int  main (int ac, char** av)
{
    if (ac > 2)
    {
        std::cerr << "this program accept only one argument\n";
        return (1);
    }
    else if (ac == 2)
    {
        try
        {
            ScalarConverter::convert(av[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return (1);
        }
    }
    else
        std::cout << "Sintaxis: ./ScalarConverter [one argument]\n";
    return 0;
}