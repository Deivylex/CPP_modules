#include "phonebook.hpp"

int main(void)
{
    try
    {

    PhoneBook phone; 
    std::string input;

    std::cout << "\033[1;33m" << "Welcome to Phonebook software" << std::endl << "\033[1;34m";
    while(1)
    {
        std::cout << "Enter a Phonebook command (ADD, SEARCH, EXIT) :" << std::endl ;
        std::getline(std::cin, input);
        if (std::cin.eof())
            throw std::runtime_error("Error");
        if (input == "ADD")
        {
            phone.add();
        }
        else if (input == "SEARCH")
        {
            phone.search();
        }
        else if (input == "EXIT")
            break ;
        else
            std::cout << "\033[1;31m" << "Invalid command!!" << std::endl << "\033[1;34m";
    }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}