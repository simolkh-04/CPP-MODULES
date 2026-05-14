#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;
class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:
        Form();
        Form(const std::string& name,  int gradeToSign,  int gradeToExecute);
        Form(const Form& other);
        Form &operator=(const Form& other);
        virtual ~Form();
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat &b);
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

};
std::ostream &operator<<(std::ostream &o, const Form &f);
#endif