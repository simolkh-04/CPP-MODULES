#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
private:
    int value;
    static int const bit;

public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed(int value);
    Fixed(float value);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    float toFloat(void) const;
    int toInt(void) const;

    int getRawBits() const;
    void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
