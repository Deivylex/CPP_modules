#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout <<  "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
    typedef void (Harl::*privateFuntion)(void);
    size_t ptrLevel = 4;
    std::string levelN[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    privateFuntion levelFuntion[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (size_t i = 0; i < ptrLevel; i++)
    {
        if (levelN[i] == level)
        {
            (this->*(levelFuntion[i]))();
            return ;
        }
    }
    std::cout << level << " ? sorry, This level did not exists in this program." << std::endl;
}