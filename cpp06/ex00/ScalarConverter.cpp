#include "ScalarConverter.hpp"
#include <iomanip>
#include <cmath> 


ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { *this = other; } 

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    if (this == &other)
        return *this;
    return *this;
}

static type isValidNumber(const std::string& str) 
{
    size_t start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
    bool hasDot = false;
    bool hasDigit = false;

    for (size_t i = start; i < str.size(); ++i) 
    {
        if (str[i] == '.') 
        {
            if (hasDot)
                throw std::runtime_error("number has more than one dot");
            hasDot = true;
        } 
        else if (std::isdigit(str[i])) 
            hasDigit = true;
        else if (str[i] == 'f' && i == str.size() - 1 && hasDigit) 
            return type::NUMBER;
        else 
            return type::ERROR;
    }
    return type::NUMBER;
}

static bool isPseudoLiteral(const std::string& str) 
{
    return str == "nan" || str == "nanf" || 
           str == "+inf" || str == "-inf" || 
           str == "+inff" || str == "-inff";
}

static bool isChar(const std::string& str) 
{ 
    if (str.size() == 3 && str.front() == '\'' && str.back() == '\'' && std::isprint(str[1]))
        return true;
    if (str.size() == 1 && std::isprint(str[0]))
        return true;
    return false;
}

type checkType(std::string arg)
{
    if (isValidNumber (arg) == type::NUMBER)
        return type::NUMBER;
    if (isPseudoLiteral(arg))
        return type::PSEUDOLITERAL;
    if (isChar(arg))
        return type::CHAR;        
    return type::ERROR;
}

static void printChar(std::string arg)
{
    char typeChar;
    if (arg.length() == 1)
        typeChar = arg[0];
    else
        typeChar = arg[1];
    int typeInt = static_cast<int>(typeChar);
    double  typeDouble = static_cast<double>(typeInt);

    std::cout << "char: " << "'" << typeChar << "'" << std::endl
              << "int: " << typeInt << std::endl
              << std::fixed << std::setprecision(1)
              << "doble: " << typeDouble << std::endl
              << "float: " << typeDouble << "f" << std::endl;
}
static void printNumbers(std::string arg)
{
    try
    {
        bool overflowInt = false;
        double typeDouble = std::stod(arg);
        int typeInt;
        try 
        {
            typeInt = std::stoi(arg);
        }
        catch (std::exception &e)
        {
            overflowInt = true;
        }
        char typeChar = static_cast<char> (typeInt);
        float typeFloat = static_cast<float>(typeDouble);
        if (!std::isprint(static_cast<unsigned char>(typeChar)) || overflowInt == true)
            std::cout << "char: " << "Non displayable" << std::endl;
        else 
            std::cout << "char: " << "'" << typeChar << "'" << std::endl;
        if (overflowInt == true)
            std::cout << "int: " << "Non displayable" << std::endl;
        else
        {
            std::cout << "int: " << typeInt << std::endl;
        }
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << typeDouble << std::endl;
        if (std::isinf(typeFloat))
            std::cout << "float: "  << typeFloat << "f" << std::endl;
        else
            std::cout << "float: "  << typeFloat << "f" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "char: " << "impossible" << std::endl
                  << "int: " << "impossible" << std::endl
                  << "double: " << "impossible" << std::endl
                  << "float: " << "impossible" << std::endl;
    }
    
}
static void printPseudoLiteral(std::string arg)
{
    if (arg == "nan")
    {
        std::cout << "char: " << "impossible" << std::endl
        << "int: " << "impossible" << std::endl
        << "doble: " << arg << std::endl
        << "float: " << arg << "f" << std::endl;
    }
    if (arg == "+inf" || arg == "-inf" || arg == "inf" || arg == "+inff" || arg == "-inff" || arg == "inff") 
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "double: " << (arg == "+inf" ? "+inf" : "-inf") << std::endl;
        std::cout << "float: " << (arg == "+inf" ? "+inff" : "-inff") << std::endl;
    }
}

void ScalarConverter::convert(std::string arg)
{
    if (arg.empty())
    {
        throw std::runtime_error("No arguments");
        return ;
    }
    type argType = checkType(arg);

    if (argType == type::CHAR)
        printChar(arg);
    else if (argType == type::NUMBER)
        printNumbers(arg);
    else if (argType == type::PSEUDOLITERAL)
        printPseudoLiteral(arg);
    else   
        throw std::runtime_error("argument imposible to convert");
}