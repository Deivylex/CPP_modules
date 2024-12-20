#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> // for rand() y srand()
#include <ctime> 

Base::~Base(){};

Base * generate(void)
{
    std::srand(std::time(nullptr)); 
    int random = std::rand() % 3;

    switch (random) 
    {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
    }
    return nullptr;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "Unknown type\n";

}

void identify(Base& p)
{
    try 
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (const std::bad_cast&) 
    {
        try 
        {
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch (const std::bad_cast&) 
        {
            try 
            {
                (void)dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch (const std::bad_cast&)
            {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}