#include "ScavTrap.hpp"

int main()
{
    ScavTrap x("said");
    x.attack("enemy");
    x.takeDamage(3);
    x.beRepaired(2);
    x.guardGate();
    return 0;
}