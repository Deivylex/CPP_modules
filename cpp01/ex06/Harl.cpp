#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug( void )
{
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger."<< std::endl;
    std::cout << "I really do!\n" << std::endl;
}

void Harl::info( void )
{
    std::cout <<  "[ INFO ]\nI cannot believe adding extra bacon costs more money." << std::endl;
    std::cout <<  "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error( void )
{
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void    Harl::printComplain(void (Harl::*funtionPtr[])(), size_t level)
{
    size_t maxLevel = 4;
    switch (level)
    {
    case 0:
    {
        while (level < maxLevel)
            (this->*(funtionPtr[level++]))();
        break;
    }
    case 1:
    {
        while (level < maxLevel)
            (this->*(funtionPtr[level++]))();
        break;
    }
    case 2:
    {
        while (level < maxLevel)
            (this->*(funtionPtr[level++]))();
        break;
    }
    case 3:
    {
        (this->*(funtionPtr[level]))();
        break;
    }
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}

void Harl::complain( std::string level )
{
    typedef void (Harl::*privateFuntionPtr)(void);
    size_t ptrLevel = 4;
    size_t i;
    std::string levelN[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    privateFuntionPtr levelFuntion[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (i = 0; i < ptrLevel; i++)
    {
        if (levelN[i] == level)     
            break ;
    }
    printComplain(levelFuntion, i);
}