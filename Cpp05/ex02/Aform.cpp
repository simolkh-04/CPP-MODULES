#include "Bureaucrat.hpp"
#include "Aform.hpp"

AForm::AForm():_name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{}
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute):_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}
AForm::AForm(const AForm& other)
: _name(other._name), _isSigned(other._isSigned),
_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{}
AForm &AForm::operator=(const AForm &other)
{
    if(this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}
AForm::~AForm(){}
std::string AForm::getName() const{
    return _name;
}
bool AForm::getIsSigned() const{
    return _isSigned;
}
int AForm::getGradeToSign() const{
    return _gradeToSign;
}
int AForm::getGradeToExecute() const{
    return _gradeToExecute;
}
void AForm::beSigned(const Bureaucrat &b)
{
    if(b.getGrade() > _gradeToSign)
    {
        throw AForm::GradeTooLowException();
    }
    _isSigned = true;
}
std::ostream &operator<<(std::ostream &o, const AForm &f) {
     o << "Form: " << f.getName() 
       << " | Signed: " << (f.getIsSigned() ? "Yes" : "No")
       << " | Grade to Sign: " << f.getGradeToSign()
       << " | Grade to Execute: " << f.getGradeToExecute();
     return o;
 }