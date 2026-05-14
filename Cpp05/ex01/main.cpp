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
        std::cout << contract << std::endl;
        std::cout << "tente de stagiaire pour sign" << std::endl;
        s.signForm(contract);
        std::cout << "tente de simo pour sign" << std::endl;
        b.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch(std::exception &e)
    {
        std::cerr << "Erreure" << e.what() << std::endl;
    }
}