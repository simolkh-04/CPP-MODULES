#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat s("simo", 150);
        std::cout << s << std::endl;
        s.incrementGrade();
        std::cout << "apre increment : " << s << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "exception capture " << e.what() << std::endl;
    }
}