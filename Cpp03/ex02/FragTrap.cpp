#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
    std::cout << "FragTrap parameterized constructor called" << std::endl;
    Hit_points = 100;
    Energy = 100;
    Attack_damage = 30;
}
FragTrap::FragTrap():ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    Hit_points = 100;
    Energy = 100;
    Attack_damage = 30;
}
FragTrap::FragTrap(const FragTrap &other):ClapTrap(other)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = other;
}
FragTrap::~FragTrap()
{
    std::cout << " FragTrap destructor called" << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if(this != &other)
        ClapTrap::operator=(other);
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap request high-fives" << std::endl;
}
