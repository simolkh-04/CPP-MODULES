#include "Zombie.hpp"

void randomChamp(std::string name)
{
    std::cout << "Creating stack zombie" << std::endl;
    Zombie z(name);
    z.announce();
}