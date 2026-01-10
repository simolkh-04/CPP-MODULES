#include <iostream>

int main(int ac, char **av)
{
    if(ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        int i = 1;
        while (av[i])
        {
            int j = 0;
            while (av[i][j])
            {
                std::cout << (char)toupper(av[i][j]);
                j++;
            }
            std::cout << " ";
            i++;
        }
        
    }
    std::cout << "\n";
}