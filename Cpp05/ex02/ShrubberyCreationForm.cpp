#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
AForm("Shrubbery Creation", 145, 137), _target(target){}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
AForm(other), _target(other._target){}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    beExecuted(executor);
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    if(!outfile.is_open())
    {
        std::cerr << "creation de fichier failed" << std::endl;
        return;
    }
    outfile << "     ceeeee       \n"
            << "   eeeeeeeee       \n"
            << " eeeeeeeeeeee     \n"
            << "eeeeeeeeeeeeee    \n"
            << "     |||||        \n"
            << "     |||||        \n"
            << "==================\n";
    outfile.close();
    // std::cout << executor.getName() << " successfully created a shrubbery file at " << filename << std::endl;
}