#pragma once
#include <map>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <regex>

class BitcoinExchange
{
    private :

    std::map <std::string, float> dataBase;
    std::string error;

    public :

    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void setDataBase();
    void checkSyntax(std::string str);
    void printMap();
    void handleImput(std::string input);
    bool inputSyntaxCheck(std::string str);

};