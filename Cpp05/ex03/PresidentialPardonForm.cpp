#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
    AForm("Presidential Pardon ", 25, 5), _target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
    AForm(other), _target(other._target) {}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    this->beExecuted(executor);
    
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox. " << std::endl;
}