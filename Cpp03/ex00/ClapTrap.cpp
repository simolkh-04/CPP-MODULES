#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap parameterized constructor called" << std::endl;
    _name = name;
    Hit_points = 10;
    Energy = 10;
    Attack_damage = 0;
}
ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor called" << std::endl;
    _name = "";
    Hit_points = 10;
    Energy = 10;
    Attack_damage = 0;
}
ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = other;
}
ClapTrap::~ClapTrap()
{
    std::cout << " ClapTrap destructor called" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if(this != &other)
    {
        _name = other._name;
        Hit_points = other.Hit_points;
        Energy = other.Energy;
        Attack_damage = other.Attack_damage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (this->Hit_points <= 0) {
        std::cout << "ClapTrap " << _name << " is dead and can't attack!" << std::endl;
        return;
    }
    if (this->Energy <= 0) {
        std::cout << "ClapTrap " << _name << " has no energy left to attack!" << std::endl;
        return;
    }

    this->Energy -= 1;
    std::cout << "ClapTrap " << _name << " attacks " << target 
              << ", causing " << Attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    this->Hit_points -= amount;
    if (this->Hit_points < 0)
        this->Hit_points = 0;

    std::cout << "ClapTrap " << _name << " takes " << amount 
              << " points of damage! Current HP: " << Hit_points << std::endl;

    if (this->Hit_points == 0)
        std::cout << "ClapTrap " << _name << " is now dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->Hit_points <= 0 || this->Energy <= 0) {
        std::cout << "ClapTrap " << _name << " can't repair itself!" << std::endl;
        return;
    }
    
    this->Energy -= 1;
    this->Hit_points += amount;
    std::cout << "ClapTrap " << _name << " repairs itself and gains " 
              << amount << " HP!" << std::endl;
}