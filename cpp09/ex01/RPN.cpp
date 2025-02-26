#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) {}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        cont = other.cont;
    return *this;
}

void RPN::runRPN(std::string str)
{
    std::istringstream  split(str);
    std::string         token;

    while (split >> token)
    {
        std::cout << token.size() << "\n";
        if (token == "+" || token == "-" || token == "*" || std::isdigit(token[0]))
        {
            std::cout << "  si\n";
        }
    }
    
}

void RPN::handelInput(std::string input)
{
    int sepPos = 0;
    while (sepPos < input.size())
    {
        std::cout << "sepPos " << sepPos << "  size " << input.size() << "\n";
        std::string str = input.substr(sepPos, input.find_first_of("+-*/", sepPos) + 1);
        runRPN(str);
        sepPos += input.find_first_of("+-*/", sepPos) + 1;
    }
    
}