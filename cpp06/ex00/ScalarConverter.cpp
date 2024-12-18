#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { *this = other; } 

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    if (this == &other)
        return *this;
    return *this;
}

static bool isInteger(const std::string& str) 
{

    size_t start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
    for (size_t i = start; i < str.size(); ++i) 
    {
        if (!std::isdigit(str[i])) 
            return false;
    }
    return true;
}

type isFloatOrDouble(const std::string& str) 
{
    size_t start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
    bool hasDot = false;
    bool hasDigit = false;

    for (size_t i = start; i < str.size(); ++i) 
    {
        if (str[i] == '.') 
        {
            if (hasDot)
            {
                throw std::runtime_error("number has more than one dot\n");
            }
            hasDot = true;
        } 
        else if (std::isdigit(str[i])) 
        {
            hasDigit = true;
        } 
        else if (str[i] == 'f' && i == str.size() - 1 && hasDigit) 
        {
            return type::FLOAT;
        } 
        else 
        {
            return type::ERROR;
        }
    }
    return type::DOUBLE;
}

bool isPseudoLiteral(const std::string& str) 
{
    return str == "nan" || str == "nanf" || 
           str == "+inf" || str == "-inf" || 
           str == "+inff" || str == "-inff";
}

bool isChar(const std::string& str) 
{ 
    if (str.size() == 3 && str.front() == '\'' && str.back() == '\'' && std::isprint(str[1]))
        return true;
    if (str.size() == 1 && std::isprint(str[0]))
        return true;
    return false;
}

type checkType(std::string arg)
{
    if (isInteger(arg))
    {
        std::cout << "\nint\n\n";
        return type::INT;
    }
    if (isFloatOrDouble (arg) == type::FLOAT)
    {
        std::cout << "\nfloat\n\n";
        return type::FLOAT;
    }
    if (isFloatOrDouble (arg) == type::DOUBLE)
    {
        std::cout << "\ndouble\n\n";
        return type::DOUBLE;
    }
    if (isPseudoLiteral(arg))
    {
        std::cout << "\nPseudoliteral\n\n";
        return type::PSEUDOLITERAL;
    }
    if (isChar(arg))
    {
        std::cout << "\nchar\n\n";
        return type::CHAR;        
    }
    return type::ERROR;
}

void printChar(std::string arg)
{
    char str = arg[0];
    int typeInt = static_cast<int>(str);
    double  typeDouble = static_cast<double>(typeInt);
    float   typeFloat = static_cast<float>(typeDouble);

    std::cout << "Char : " << str << std::endl
              << "Int : " << typeInt << std::endl
              << "Doble : " << typeDouble << std::endl
              << "Float : " << typeFloat << std::endl;
}

void ScalarConverter::convert(std::string arg)
{
    if (arg.empty())
        return ;
    type argType = checkType(arg);

    if (argType == type::CHAR)
    {
        printChar(arg);
    }
    
}