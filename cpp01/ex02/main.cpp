#include <iostream>

int main()
{
    std::string brain = "HI THIS IS BRAIN ";
    std::string *ptr = &brain; 
    std::string &ref = brain;

    std::cout << "Memory address\n";
    std::cout << "Memory address string variable: " << &brain << "\n";
    std::cout << "Memory address stringPTR: " << &ptr << "\n";
    std::cout << "Memory address stringREF: " << &ref << "\n";

    std::cout << "\nVariables\n";
    std::cout << "string varaible: " << brain << "\n";
    std::cout << "stringPTR: " << *ptr << "\n";
    std::cout << "stringREF: " << ref << "\n";

    return 0;
}