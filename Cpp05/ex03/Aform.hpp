#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;
class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:
        AForm();
        AForm(const std::string& name,  int gradeToSign,  int gradeToExecute);
        AForm(const AForm& other);
        AForm &operator=(const AForm& other);
        virtual ~AForm();
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat &b);
        void beExecuted(const Bureaucrat& executor) const;
        virtual void execute(Bureaucrat const &executor)const = 0;
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Form grade is too high!";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Form grade is too low!";
                }
        };
        class FormNotSignedException : public std::exception{
            public:
                virtual const char* what() const throw(){
                    return "Form is not signed ";
                }
        };

};
std::ostream &operator<<(std::ostream &o, const AForm &f);
#endif