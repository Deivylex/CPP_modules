#include "Span.hpp"

int main()
{
    try 
    {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span spn(10);

    spn.addNumber(1);
    spn.addNumber(5);

    std::vector<int> moreNumbers = {10, 20, 30, 40, 50};
    spn.addNumbers(moreNumbers.begin(), moreNumbers.end());

    std::cout << "Shortest Span: " << spn.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << spn.longestSpan() << std::endl;
    }
    
    catch(const std::exception& ex)
    {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }

    try
    {
        Span s(10);

        s.addNumber(1);
        s.addNumber(5);
    
        std::vector<int> moreNumbers = {10, 20, 30, 40, 50, 60, 70, 80, 90};
        s.addNumbers(moreNumbers.begin(), moreNumbers.end());
    
        std::cout << "Shortest Span: " << s.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << s.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}