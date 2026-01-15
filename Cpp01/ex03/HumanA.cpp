#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &Weapon): _name(name), _weapon(Weapon) {}
void HumanA::Attack()
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}