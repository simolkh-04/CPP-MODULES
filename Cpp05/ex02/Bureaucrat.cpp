#include "Bureaucrat.hpp"
#include "Aform.hpp"

Bureaucrat::Bureaucrat():_name("Default"), _grade(150){}
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade){
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if(grade > 150)
        throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat &other):_name(other._name), _grade(other._grade){}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if(this != &other)
        this->_grade = other._grade;
    return *this;
}
Bureaucrat::~Bureaucrat(){}
std::string Bureaucrat::getName() const
{
    return _name;
}
int Bureaucrat::getGrade() const
{
    return this->_grade;
}
void Bureaucrat::incrementGrade()
{
    if(this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}
void Bureaucrat::decrementGrade()
{
    if(this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}
void Bureaucrat::signForm(AForm &f)
{
    try
    {
        f.beSigned(*this);
        std::cout << _name << "signed " << f.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << "couldn't signe " << f.getName() << "cuzz" << e.what() << std::endl;
    }
    
}
void Bureaucrat::executeForm(AForm const& form)
{
    try
    {
        form.execute(*this);
        std::cout << _name << "executed " << form.getName() << std:: endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << "couldn't execute " << form.getName() << "because " <<e.what() << std::endl;
    }
    
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
