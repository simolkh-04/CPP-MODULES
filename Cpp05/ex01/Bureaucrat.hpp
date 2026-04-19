#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        virtual ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade is too high! (Must be >= 1)";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade is too low! (Must be <= 150)";
                }
        };

        void incrementGrade();
        void decrementGrade();
        
    };
    std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif