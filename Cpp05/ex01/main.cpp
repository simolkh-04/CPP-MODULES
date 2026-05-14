#include "Bureaucrat.hpp"
#include "form.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat b("simo", 1);
        Bureaucrat s("stagier", 150);
        Form contract("contract important", 50, 20);
        
    }
    catch(std::exception &e)
    {
        std::cerr << "exception capture " << e.what() << std::endl;
    }
}