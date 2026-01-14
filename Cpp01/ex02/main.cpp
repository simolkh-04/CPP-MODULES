#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    //adress
    std::cout << "Adresse de la string : " << &str << std::endl;
    std::cout << "Adress via stringPTR : " << stringPTR << std::endl;
    std::cout << "Adress via stringREF : " << &stringREF << std::endl;

    //valeur
    std::cout << "la valeurde la string : " << str << std::endl;
    std::cout << "la valeurde la stringPTR : " << *stringPTR << std::endl;
    std::cout << "la valeurde la stringREF : " << stringREF << std::endl;
}