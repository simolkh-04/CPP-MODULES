#include "Fixed.hpp"

const int Fixed::bit = 8;

Fixed::Fixed() : value(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(int value)
{
    // std::cout << "constructor called" << std::endl;
    this->value = value << bit;
}

Fixed::Fixed(float value)
{
    // std::cout << "constructor called" << std::endl;
    this->value = roundf(value * (1 << bit));
}

Fixed &Fixed::operator=(const Fixed &other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
    {
        this->value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() 
{
    // std::cout << "Destructor called" << std::endl;
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
    // std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
bool Fixed::operator>(const Fixed &other) const {
    return this->value > other.value;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->value < other.value;
}
bool Fixed::operator>=(const Fixed &other) const {
    return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->value != other.value;
}

Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->value++;
    return temp;
}

Fixed &Fixed::operator--()
{
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->value--;
    return temp;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if(a > b)
        return a;
    return b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if(a > b)
        return a;
    return b;
}
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if(a < b)
        return a;
    return b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if(a < b)
        return a;
    return b;
}