#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
    this->_brain = new Brain();
}
Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
}
Dog::Dog(const Dog &other): Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_brain = new Brain(*(other._brain));
}
Dog &Dog::operator=(const Dog &other)
{
    if(this != &other)
    {
        this->type = other.type;
        if(this->_brain)
            delete _brain;
        this->_brain = new Brain(*(other._brain));
    }
    return *this;
}

void Dog::makeSound () const
{
    std::cout << "Woof! Woof!" << std::endl;
}