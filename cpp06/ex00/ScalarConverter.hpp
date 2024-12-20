#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


#include <iostream>

enum class type {
    CHAR,
    NUMBER,
    PSEUDOLITERAL,
    ERROR
};

class ScalarConverter
{
    private :
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);

    public :

    static void convert(std::string arg);

};


#endif