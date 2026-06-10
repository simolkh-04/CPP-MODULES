#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
    AForm("Robotomy Request", 72, 45), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
    AForm(other), _target(other._target) {}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    this->beExecuted(executor); 

    std::cout << "* BZZZZZZZZZZ... DRILL NOISES... CLANK! *" << std::endl;
    if (std::rand() % 2 == 0)
    {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << "The robotomy on " << _target << " failed." << std::endl;
    }
}