#include "Zombie.hpp"

int main()
{
    Zombie *heap_z = newZombie("heap zombie");
    heap_z->announce();

    randomChamp("stack zombie");
    delete heap_z;
    return 0;
}