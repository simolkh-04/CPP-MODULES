#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm* Intern::createShrubbery(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}
AForm* Intern::createRobotomy(const std::string& target) const {
    return new RobotomyRequestForm(target);   
}
AForm* Intern::createPardon(const std::string& target) const {
    return new PresidentialPardonForm(target);
}
