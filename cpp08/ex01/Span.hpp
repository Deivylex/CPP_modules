#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
    private :
    unsigned int _N;
    std::vector<int> _numbers;
    unsigned int index;


    public :

    Span(unsigned int N);
    ~Span();
    void addNumber(unsigned int number);
    template <typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end)
    {
        if (_numbers.size() + std::distance(begin, end) > _N)
            throw std::overflow_error("Adding these numbers would exceed the limit");
        _numbers.insert(_numbers.end(), begin, end);
    }
    int shortestSpan() const;
    int longestSpan() const;

};