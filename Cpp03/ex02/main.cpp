#include "FragTrap.hpp"

int main()
{
    FragTrap x("said");
    x.attack("enemy");
    x.takeDamage(3);
    x.beRepaired(2);
    x.highFivesGuys();
    return 0;
}