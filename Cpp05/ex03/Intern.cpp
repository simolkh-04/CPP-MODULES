#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}
Intern::Intern(const Intern& other){(void)other; }
Intern& Intern::operator=(const Intern& other){(void)other; return *this;}
Intern::~Intern(){}

AForm* Intern::createShrubbery(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}
AForm* Intern::createRobotomy(const std::string& target) const {
    return new RobotomyRequestForm(target);   
}
AForm* Intern::createPardon(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const{
    const std::string names[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    FormCreator creators[] = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPardon,
    };
    for(int i = 0; i < 3; i++){
        if(formName == names[i]){
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*creators[i])(target);
        }
    }
    std::cerr << "Error: Intern cannot create '" << formName << "' (Unknown form)" << std::endl;
    return NULL;
}