#include "ClapTrap.hpp"

int main()
{
    ClapTrap x("said");
    x.attack("enemy");
    x.takeDamage(3);
    x.beRepaired(2);
    return 0;
}