#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) {}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        content = other.content;
    return *this;
}

void RPN::RPMcalculetor(tokens OP)
{
    if (content.empty())
        return ;
    int result;
    switch (OP)
    {
        case SUM:
            result = content.top();
            content.pop();
            while (!content.empty())
            {             
                result += content.top();
                content.pop();
            }            
            break;
        case REST:
            result = content.top();
            content.pop();
            while (!content.empty())
            {
                if (result < content.top())
                    result = content.top() - result;
                else
                    result -= content.top();
                content.pop();
            } 
            break;
        case MULT:
            result = content.top();
            content.pop();
            while (!content.empty())
            {
                result *= content.top();
                content.pop();
            } 
            break;
        case DIV://need to check this which value can not be 0
            result = content.top();
            if (result == 0)
                throw std::runtime_error("Error: division by 0 is not possible");
            content.pop();
            while (!content.empty())
            {
                result = content.top() / result;
                content.pop();
            } 
            break;
    }
    content.push(result);
}

void RPN::runRPN(std::string str)
{
    //std::cout << str << "\n";
    std::istringstream  split(str);
    std::string         token;

    while (split >> token)
    {
        //std::cout << "int " << token << "\n";
        if (token.size() > 1)
            throw std::runtime_error("Error");
        if (token == "+" || token == "-" || token == "*" || token == "/" || std::isdigit(token[0]))
        {
            switch (token[0])
            {
                case '+':
                    RPMcalculetor(SUM);
                    break;
                case '-':
                    RPMcalculetor(REST);
                    break;
                case '*':
                    RPMcalculetor(MULT);
                    break;
                case '/':
                    RPMcalculetor(DIV);
                    break;
                default:
                    content.push(std::stoi(token));
                    break;
            }
        }
        else
            throw std::runtime_error("Error");
    }
    
}

void RPN::handelInput(std::string input)
{
    int sepPos = 0;
    while (sepPos < input.size())
    {
        //std::cout << sepPos << "   " << input.find_first_of("+-*/", sepPos) <<"\n";
        std::string str = input.substr(sepPos, input.find_first_of("+-*/", sepPos) - sepPos + 1);
        runRPN(str);
        sepPos = input.find_first_of("+-*/", sepPos) + 1;
    }
    std::cout << content.top() << "\n";
    
}