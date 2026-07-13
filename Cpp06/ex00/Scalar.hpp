#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include<iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cmath>

class ScalarConverter{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const &src);
        ~ScalarConverter();
        ScalarConverter &operator=(ScalarConverter const &src);
    public:
        static void convert(const std::string &literal);
};
#endif