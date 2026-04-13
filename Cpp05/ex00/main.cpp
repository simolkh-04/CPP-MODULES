#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat b("simo", 151);
        // std::cout << b << std::endl;
        // b.incrementGrade();
        // std::cout << "apre increment : " << b << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "exception capture " << e.what() << std::endl;
    }
}