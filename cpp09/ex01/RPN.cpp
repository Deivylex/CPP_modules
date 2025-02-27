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

void RPN::RPMcalculator(tokens OP)
{
    if (content.size() != 2)
        throw std::runtime_error("Error\n");
    float       a;
    float       b;
    float       result;
    switch (OP)
    {
        case SUM:
            b = content.top();
            content.pop();
            a = content.top();
            result = a + b;
            content.pop();     
            break;
        case REST:
            b = content.top();
            content.pop();
            a = content.top();
            result = a - b;
            content.pop(); 
            break;
        case MULT:
            b = content.top();
            content.pop();
            a = content.top();
            result = a * b;
            content.pop();
            break;
        case DIV:
            b = content.top();
            if (b == 0)
                throw std::runtime_error("Error: not possible division by 0");
            content.pop();
            a = content.top();
            result = a / b;
            content.pop(); 
            break;
    }
    content.push(result);
}

char findOp(std::string str)
{
    std::istringstream  split(str);
    std::string         token;

    while (split >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
            return token[0];
    }
    return (' ');
}

void RPN::runRPN(std::string str)
{
    if (str.size() == 1)
        throw std::runtime_error("Error");
    std::istringstream  split(str);
    std::string         token;

    char op = findOp(str);
    while (split >> token)
    {
        if (token.size() > 1)
            throw std::runtime_error("Error");
    
        if (std::isdigit(token[0]))
        {
            content.push(std::stoi(token));
            if(content.size() == 2)
            {
                switch (op)
                {
                    case '+':
                        RPMcalculator(SUM);
                        break;
                    case '-':
                        RPMcalculator(REST);
                        break;
                    case '*':
                        RPMcalculator(MULT);
                        break;
                    case '/':
                        RPMcalculator(DIV);
                        break;
                    default :
                        break;
                }
            }
        }
        else if(token[0]  == op)
            break;
        else
            throw std::runtime_error("Error");
    }
    if (content.size() == 0)
        throw std::runtime_error("Error");
}

void RPN::handelInput(std::string input)
{
    int sepPos = 0;
    while (sepPos < input.size())
    {
        int op = input.find_first_of("+-*/", sepPos);
        if (op == std::string::npos)
            throw std::runtime_error("Error"); ;
        std::string str = input.substr(sepPos, op - sepPos + 1);
        runRPN(str);
        sepPos = op + 1;
    }
    std::cout << content.top() << "\n";
    
}