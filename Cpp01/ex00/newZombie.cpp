#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    std::cout << "Creating heap zombie" << std::endl;
    return new Zombie(name);
}