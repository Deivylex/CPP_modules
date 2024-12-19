#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


#include <iostream>

enum class type {
    CHAR,
    NUMBER,
    PSEUDOLITERAL,
    ERROR
};

void printChar(std::string arg);
void printInt(std::string arg);
void printFloat(std::string arg);
void printDouble(std::string arg);
type checkType(std::string arg);


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