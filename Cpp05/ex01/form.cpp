#include "Bureaucrat.hpp"
#include "form.hpp"

Form::Form():_name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{}
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute):_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}
Form::Form(const Form& other)
: _name(other._name), _isSigned(other._isSigned),
_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{}
Form &Form::operator=(const Form &other)
{
    if(this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}
Form::~Form(){}
std::string Form::getName() const{
    return _name;
}
bool Form::getIsSigned() const{
    return _isSigned;
}
int Form::getGradeToSign() const{
    return _gradeToSign;
}
int Form::getGradeToExecute() const{
    return _gradeToExecute;
}
void Form::beSigned(const Bureaucrat &b)
{
    if(b.getGrade() > _gradeToSign)
    {
        throw Form::GradeTooLowException();
    }
    _isSigned = true;
}
std::ostream &operator<<(std::ostream &o, const Form &f) {
     o << "Form: " << f.getName() 
       << " | Signed: " << (f.getIsSigned() ? "Yes" : "No")
       << " | Grade to Sign: " << f.getGradeToSign()
       << " | Grade to Execute: " << f.getGradeToExecute();
     return o;
 }