#include "Base.hpp"

int main()
{
    Base* base = generate();

    std::cout << "Identifying with pointer: \n";
    identify(base);

    std::cout << "Identifying with reference: \n";
    identify(*base);

    delete base;

    return 0;
}