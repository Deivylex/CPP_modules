#pragma once

#include <stack>
#include <iostream>
#include <algorithm>
#include <sstream>


enum token
{
    SUM,
    REST,
    MULT,
    DIV
};

class RPN 
{
    private:
    
    std::stack <int> cont;

    public:

    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    void handelInput(std::string input);
    void runRPN(std::string str);
};
