#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    int i;
    int i2;
    int check;

    check = 1;
    if(ac > 1)
    {
        i = 1;
        while (av[i])
        {
            if (av[i][0] == '\0')
                check++;
            else 
            {
                i2 = 0;
                while (av[i][i2])
                {
                    av[i][i2] = (char)toupper(av[i][i2]);
                    i2++;
                }
                std::cout << av[i];
            }
            i++;
        }
    }
    if (ac == 1 || check == ac)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}