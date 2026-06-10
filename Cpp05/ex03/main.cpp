#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL));
    std::cout << "initialisation des Buracrates " << std::endl;
    Bureaucrat boss("le boss ", 1);
    Bureaucrat assistant("l'assistant ", 40);
    Bureaucrat stagiaire("le stagiaire ", 150);

    std::cout << boss << std::endl;
    std::cout << assistant << std::endl;
    std::cout << stagiaire << std::endl;

    std::cout << "test 1 : Shrubbery creation form " << std::endl;
    ShrubberyCreationForm shrub("home ");
    std::cout << shrub << std::endl;
    stagiaire.executeForm(shrub);
    assistant.signForm(shrub);
    std::cout << shrub << std::endl;
    stagiaire.executeForm(shrub);
    assistant.executeForm(shrub);

    std::cout << "test 2 : Robotomy request form" << std::endl;
    RobotomyRequestForm robot("ClapTrap");
    boss.signForm(robot);
    std::cout << "--- Tentative 1 ---" << std::endl;
    boss.executeForm(robot);
    std::cout << "--- Tentative 2 ---" << std::endl;
    boss.executeForm(robot);
    std::cout << "--- Tentative 3 ---" << std::endl;
    boss.executeForm(robot);

    std::cout << "test 3 : Presidential pardon form" << std::endl;
    PresidentialPardonForm pardon("Double-Fourchette");
    assistant.signForm(pardon);
    boss.signForm(pardon);
    assistant.executeForm(pardon);
    boss.executeForm(pardon);
}