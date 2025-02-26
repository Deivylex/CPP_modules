#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
    if(ac != 2)
    {
        std::cout << "Error: could not open file.\n";
        return (1);
    }
    try
    {
        BitcoinExchange btc;
        btc.setDataBase(av[1]);
        btc.handleImput(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
    return (0);
}