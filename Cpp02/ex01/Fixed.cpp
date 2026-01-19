#include "Fixed.hpp"

const int Fixed::bit = 8;

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(int value)
{
    std::cout << "constructor called" << std::endl;
    this->value = value << bit;
}

Fixed::Fixed(float value)
{
    std::cout << "constructor called" << std::endl;
    this->value = roundf(value * (1 << bit));
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
    {
        this->value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat()const
{
    return (float)value / (1 << bit);
}

int Fixed::toInt()const
{
    return value >> bit;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    std::cout << fixed.toFloat();
    return out;
}