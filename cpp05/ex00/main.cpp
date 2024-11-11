#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout << "grade too hight -1000-------------> \n";
        Bureaucrat test("test1", -1000);
        std::cout << test << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "grade too low 151------------->\n";
        Bureaucrat test("tes2", 151);
        std::cout << test << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "grade 150-------------> \n";
        Bureaucrat test("test3", 150);
        std::cout << test << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "grade 1-------------> \n";
        Bureaucrat test("test4", 1);
        std::cout << test << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "decrementGrade 145------------->\n";
        Bureaucrat test5("test5", 145);
        while (1)
        {
            test5.decrementGrade();
            std::cout << test5 << std::endl;
        }
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "incrementGrade 5------------->\n";
        Bureaucrat test6("test6", 5);
        while (1)
        {
            test6.incrementGrade();
            std::cout << test6 << std::endl;
        }
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
} 
