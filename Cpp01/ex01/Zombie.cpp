#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
    this->_name = "NAME : ";
}

Zombie::~Zombie()
{
    std::cout << _name << ": has been destroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
    this->_name = name;
}

void Zombie::announce()
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
