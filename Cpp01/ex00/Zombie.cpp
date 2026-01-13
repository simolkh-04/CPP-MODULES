#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
{
    _name = name;
}
Zombie::~Zombie()
{
    std::cout << _name << ": has been destroyed" << std::endl;
}
void Zombie::announce()
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie *newZombie(std::string name)
{
    std::cout << "Creating heap zombie" << std::endl;
    return new Zombie(name);
}

void randomChamp(std::string name)
{
    std::cout << "Creating stack zombie" << std::endl;
    Zombie z(name);
    z.announce();
}
int main()
{
    Zombie *heap_z = newZombie("heap zombie");
    heap_z->announce();
    randomChamp("stack zombie");
    delete heap_z;
}