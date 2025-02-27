#include "RPN.hpp"

bool checkArg(std::string str)
{
    std::istringstream  split(str);
    std::string         token;

    while(split >> token)
    {
        if (token.size() > 1)
            throw std::runtime_error("Error");
        if (token == "+" || token == "-" || token == "*" || token == "/")
            continue;
        if (std::isdigit(token[0]) != 0)
            continue;
        else
            throw std::runtime_error("Error");
    }
    return true;
}

std::string joinArg(int ac, char **av) // "1 2 3 +" " 8 "
{
    std::string arg = "";
    for(int i = 1; i < ac; i++)
    {
        std::string token = av[i];
        if (token.size() > 1)
        {
            if (!checkArg(token))
                throw std::runtime_error("Error");
        }
        else if (token != "+" && token != "-" && token != "*" && token != "/" && std::isdigit(token[0]) == 0)
            throw std::runtime_error("Error 2");
        arg +=  token;
        if (i + 1 != ac)
            arg += " ";
    }
    return arg;
}

int main(int ac, char** av)
{
    if (ac == 1)
        return 0;
    std::string arg;
    try
    { 
        if (ac != 2)
        {
            arg = joinArg(ac, av);
        }
        if (arg.size() == 0)
            arg = av[1];
        RPN rpn;
        rpn.handelInput(arg);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}