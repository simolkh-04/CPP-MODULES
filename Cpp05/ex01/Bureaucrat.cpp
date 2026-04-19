#include "Bureaucrat.hpp"

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
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}