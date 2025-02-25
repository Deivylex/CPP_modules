#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
    BitcoinExchange btc;
    btc.setDataBase();
    btc.handleImput(av[1]);

}