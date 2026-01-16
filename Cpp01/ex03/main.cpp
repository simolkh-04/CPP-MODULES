#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA ana("ana", club);
        ana.Attack();
        club.setType("some other type of club");
        ana.Attack();
    }

    {
        Weapon club = Weapon("crude spiked club");
        HumanB ana2("ana2");
        ana2.setWeapon(club);
        ana2.Attack();
        club.setType("some other type of club");
        ana2.Attack();
    }
    return 0;
}