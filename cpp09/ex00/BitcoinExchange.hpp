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

    public :

    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void    setDataBase(std::string input);
    void    checkSyntax(std::string str);
    void    handleImput(std::string input);
    bool    inputSyntaxCheck(std::string str);
    float   getClosestValue(const std::string &date);

};