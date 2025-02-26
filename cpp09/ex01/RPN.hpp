#pragma once

#include <stack>
#include <iostream>
#include <algorithm>
#include <sstream>


enum tokens
{
    SUM,
    REST,
    MULT,
    DIV
};

class RPN 
{
    private:
    
    std::stack <int> content;
    int ret;

    public:

    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    void handelInput(std::string input);
    void runRPN(std::string str);
    void RPMcalculetor(tokens OP);
};
