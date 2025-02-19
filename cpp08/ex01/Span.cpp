#include "Span.hpp"
#include <limits>

Span::Span(unsigned int N) : _N(N), index(0) { 
}
Span::~Span() {}

void Span::addNumber(unsigned int number) 
{
    if (index >= _N)
        throw std::overflow_error("\nSpan is full");
    _numbers.push_back(number);
    index += 1;
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span.");

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        minSpan = std::min(minSpan, sorted[i] - sorted[i - 1]);
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough numbers to find a span.");

    int minValue = *std::min_element(_numbers.begin(), _numbers.end());
    int maxValue = *std::max_element(_numbers.begin(), _numbers.end());

    return maxValue - minValue;
}