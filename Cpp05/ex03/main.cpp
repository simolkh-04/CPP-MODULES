#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::srand(std::time(NULL));
    
    Intern someRandomIntern;
    AForm* rrf;
    
    std::cout << "=== Test 1: Valid forms ===" << std::endl;
    
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
    {
        std::cout << *rrf << std::endl;
        delete rrf;
    }
    
    rrf = someRandomIntern.makeForm("presidential pardon", "Doop");
    if (rrf)
    {
        std::cout << *rrf << std::endl;
        delete rrf;
    }
    
    rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (rrf)
    {
        std::cout << *rrf << std::endl;
        delete rrf;
    }
    
    std::cout << "\n=== Test 2: Unknown form ===" << std::endl;
    rrf = someRandomIntern.makeForm("unknown form", "Target");
    
    return 0;
}