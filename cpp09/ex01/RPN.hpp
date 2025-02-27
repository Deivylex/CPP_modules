#pragma once

#include <stack>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <regex>
#include <cctype>


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
    
    std::stack <float> content;

    public:

    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    void handelInput(std::string input);
    void runRPN(std::string str);
    void RPMcalculator(tokens OP);
};
