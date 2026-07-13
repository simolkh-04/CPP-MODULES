#include "Scalar.hpp"
#include <iomanip>

void ScalarConverter::convert(const std::string &literal)
{
    if (literal == "nan" || literal == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
        return;
    }
    if (literal == "-inf" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }
    char *end;
    double val = std::strtod(literal.c_str(), &end);
    if(*end != '\0' && *end != 'f')
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    if (val < CHAR_MIN || val > CHAR_MAX)
    {
        std::cout << "char: impossible" << std::endl;
    } 
    else 
    {
        char c = static_cast<char>(val);
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    if(val < INT_MIN || val < INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int : " << static_cast<int>(val) << std::endl;
    std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
    std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl;
    
}