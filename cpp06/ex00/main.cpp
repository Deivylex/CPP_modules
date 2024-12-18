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
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl; 
        }
    }
    return 0;
}