#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
    std::cout << "ScavTrap parameterized constructor called" << std::endl;
    Hit_points = 100;
    Energy = 50;
    Attack_damage = 20;
}
ScavTrap::ScavTrap():ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    Hit_points = 100;
    Energy = 50;
    Attack_damage = 20;
}
ScavTrap::ScavTrap(const ScavTrap &other):ClapTrap(other)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    *this = other;
}
ScavTrap::~ScavTrap()
{
    std::cout << " ScavTrap destructor called" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if(this != &other)
        ClapTrap::operator=(other);
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (this->Hit_points <= 0) {
        std::cout << "ScavTrap " << _name << " is dead and can't attack!" << std::endl;
        return;
    }
    if (this->Energy <= 0) {
        std::cout << "ScavTrap " << _name << " has no energy left to attack!" << std::endl;
        return;
    }

    this->Energy -= 1;
    std::cout << "ScavTrap " << _name << " attacks " << target 
              << ", causing " << Attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << " ScavTrap is now in Gate keeper mode." << std::endl;
}
